## Getting Started

1. Clone repository to desktop.
2. Switch to your branch.
3. Run `npm install`
4. Run `gulp`

`gulp` will process files and open the site in a browser tab with a URL that is accessible by any device. In addtion, it will detect changes to source code and auto reload the browser.

### Initial Setup
1. Update the URL in `gulpfile.babel.js` to the native URL on your WAMP server. i.e if `http://localhost/wordpress/` opens up the site, change gulpfile URL to this.
2. Install `woocommerce` plugin and activate it.
3. Update fonts in `/functions/typography.php`
4. Add site color variable to `src/sass/variables-site/_colors.scss`