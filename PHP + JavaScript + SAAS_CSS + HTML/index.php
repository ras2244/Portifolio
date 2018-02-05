<?php /*
Theme Name: Alexa2
Theme URI: 
Description: Just a tutorial
Author: 
Author URI: 
Version: 1.0
Tags: responsive, white, bootstrap

License:
License URI: 

This simple theme was built using the example Bootstrap theme "Basic marketing site" found on the Bootstrap web site http://twitter.github.com/bootstrap/examples/hero.html
*/ ?>

<!-- ########## Header Section ########## -->
	<?php get_header(); ?>


<!-- ########## Body Section ########## -->
	
	<!-- Template URL components -->
	<?php

		// carousel
		get_template_part( 'template-parts/landing-page/carousel');

		// body-content part-1
		get_template_part( 'template-parts/landing-page/content-part-1');

		// body-content part-2
		get_template_part( 'template-parts/landing-page/content-part-2');
	?>


<!-- ########## Sidebar Section ########## -->
	<?php //get_sidebar(); ?>


<!-- ########## Footer Section ########## -->
	<?php get_footer(); ?>
