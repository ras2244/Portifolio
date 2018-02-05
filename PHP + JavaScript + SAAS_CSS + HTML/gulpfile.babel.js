/**
 * This gulpfile does the following;
 *    1. Processes Sass and JavaScript differently based on NODE_ENV or variable env value.
 *        a. Processes Sass, lints PHP, lints and concatenates all JavaScript files in to one, and places the resulting php, style.css and script.js file in,
 *            i. If NODE_ENV/env==='development' or default => root folder.
 *           ii. If NODE_ENV/env==='production' => 'builds'. CSS will also be compressed. JavaScript will be minified.
 *    2. Display any JavaScript errors or warning on the console.
 *    3. If NODE_ENV==='production' optimize images, and store them in 'builds/src/images'.
 *    4. Auto reloads browser if changes were made in any PHP, Sass, JavaScript, or image file.
 *    5. Allows multiple devices to view the processed web site at a given URL, as long as all devices are connected to the same network.
 *    6. Supports ES6 JavaScript processed using Babel.
 *
 * To set the NODE_ENV value type in console, `set NODE_ENV=development` (Windows).
 *
 * To work in development mode, type gulp
 * To generate production files, type gulp build
 *
 * @type Module gulp|Module gulp
 * @version 2.0
 */

// *****----------Variables----------*****
var gulp = require('gulp'),
    gutil = require('gulp-util'),
    browserSync = require('browser-sync').create(), // Browser auto refreshing and syncing between devices.
    gulpif = require('gulp-if'), // If statements with gulp.
    changed = require('gulp-changed'), // Only work with new or updated files.
    imagemin = require('gulp-imagemin'), // For image optimization.
    sass = require('gulp-sass'), // For Processing Sass.
    autoprefixer = require('autoprefixer'), // Parse CSS and add vendor prefixes to CSS rules using values from "Can I Use".
    postcss = require('gulp-postcss'), // For piping CSS through several plugins, but parse CSS only once. (Used with Autoprefixer plugin).
    sourcemaps = require('gulp-sourcemaps'), // Shows which Sass file is affecting styles on an element when using browser debugging tools.
    phplint = require('gulp-phplint'), // PHP linter.
    cached = require('gulp-cached'), // Creates a file cache. Sends only updated files downstream.
    uglify = require('gulp-uglify'), // Compress JavaScript with UglifyJS2.
    babel = require('gulp-babel'), // For JavaScipt ES6 support.
    eslint = require('gulp-eslint'), // Used to detect errors and potential problems in JavaScript code.
                                     // Follows Wordpress JavaScript standards https://make.wordpress .org/core/handbook/best-practices/coding-standards/javascript/
    pump = require('pump'), // Sends errors downstream.
    clean = require('gulp-clean'), // Removes files and folders.
    copy = require('gulp-copy'), // Copies files/folders to a destination.
    // rename = require('gulp-rename'), // For renaming files (e.g script.js -> script.min.js)
    runSequence = require('run-sequence'), // Run tasks in a defined sequence
    cls = require('clear'), // Clear terminal if possible
    concat = require('gulp-concat'); // Used to concatenate all JavaScript in to one file.

var env,
    jsSources,
    sassSources,
    imgSources,
    outputDir,
    localhostURL = 'http://localhost/wordpress/', //Used by browserSync. Add localhost URL. // TODO Update URL
    sassStyle;

//*****----------Build Conditions----------*****
env = process.env.NODE_ENV || 'development';

buildParams();

function buildParams() {
  if (env === 'development') {
    outputDir = './';
    sassStyle = 'expanded';
  } else {
    outputDir = 'builds/';
    sassStyle = 'compressed';
  }
}

//*****----------Sources----------*****
sassSources = ['./src/sass/'];
jsSources = ['./src/js/'];
imgSources = './src/images/';

//*****----------Tasks----------*****

/*
 * Delete builds folder
 *
 */
gulp.task('clean', function () {
  return gulp.src('builds', {read: false})
  // .pipe(gulpif(env === 'production', clean()));
      .pipe(clean());
});

/*
 * Clean File Cache
 * WIP
 */
gulp.task('clear_cache', function () {
  return gulpif(env === 'production', cached.caches = {});
});

/*
 * Copy files/folders in production mode
 *
 */
gulp.task('copy', function () {
  return gulp.src('./screenshot.png')
      .pipe(gulpif(env === 'production', copy('builds/')))
});

/*
 * PHP
 *
 */
gulp.task('phplint', function() {
  return gulp.src(['./**/*.php', '!./code_bucket.php', '!./builds/**/*.php'])
      .pipe(cached('phplinting'))
      .pipe(phplint())
      .pipe(gulpif(env === 'production', gulp.dest(outputDir)));
});

/*
 * CSS and Sass
 *
 */
gulp.task('css', function() {
  return gulp.src([sassSources + 'style.scss', sassSources + 'woocommerce.scss'])
      .pipe(sourcemaps.init())
      .pipe(sass({
        outputStyle: sassStyle,
        indentType: 'tab',
        indentWidth: '1'
      }).on('error', sass.logError))
      // .pipe(gulpif(env === 'production', rename({ suffix: '.min' })))
      .pipe(cached('sass_compile'))
      .pipe(postcss([
        autoprefixer('last 2 versions', '> 1%')
      ]))
      .pipe(gulpif(env === 'development', sourcemaps.write(sassSources + 'maps')))
      .pipe(gulp.dest(outputDir))
});

/*
 * JavaScript
 *
 */
gulp.task('javascript', function() {
  return pump([
    gulp.src(jsSources + ['**/*.js', '!./builds/**/*.js']),
    // gulp.src([jsSources + '**/*.js', '!' + jsSources + '/lib/*.js']),
    babel(),
    eslint(),
    eslint.format(),
    // eslint.failOnError(), // Stops gulp task on linter errors
    gulpif(env === 'production', uglify())
  ])
      .pipe(concat('script.js'))
      // .pipe(gulpif(env === 'production', rename({ suffix: '.min' })))
      .pipe(gulp.dest(outputDir))
});

/*
 * Images
 *
 */
gulp.task('images', function() {
  return gulp.src(imgSources + '**/*.{jpg,JPG,png}')
      .pipe(gulpif(env === 'production', changed('./build/production/images')))
      .pipe(gulpif(env === 'production', imagemin()))
      .pipe(gulpif(env === 'production', gulp.dest(outputDir + 'src/images')))
});


// TODO Reload browser even after error
//*****----------Watch----------*****
gulp.task('watch', function() {
  browserSync.init({
    open: 'external',
    baseDir: './',
    proxy: localhostURL,
    port: 81
  });
  gulp.watch([sassSources + '**/*.*'], ['css']).on('change', browserSync.reload);
  gulp.watch(jsSources + '**/*.js', ['javascript']).on('change', browserSync.reload);
  gulp.watch(['./**/*.php'], ['phplint']).on('change', browserSync.reload);
  gulp.watch(imgSources + '**/*.{jpg,JPG,png}', ['images']).on('change', browserSync.reload);
});


// Default task (runs at initiation: gulp)
// gulp.task('default', ['css', 'phplint', 'javascript', 'images', 'watch']);
gulp.task('default', function() {
  env = 'development';
  cls();
  console.log('\n\n!!----- Running Gulp in ' + env + ' mode. -----!!\n\n');
  buildParams();
  runSequence('css', 'phplint', 'javascript', 'images', 'watch');
});

gulp.task('build', function(cb) {
  env = 'production';
  cls();
  console.log('\n\n!!----- Running Gulp in ' + env + ' mode. -----!!\n\n');
  buildParams();
  runSequence('clean', 'clear_cache','copy', 'css', 'phplint', 'javascript', 'images', (cb => {
    env = 'development';
    console.log('\n\n!!----- Done! See ./build. Reverting build conditions to ' + env + ' mode. -----!!\n\n');
    buildParams();
  }));
});
