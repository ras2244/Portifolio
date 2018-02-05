<?php

// EXAMPLE : Require files from /inc/
//Widget for the text area after the carousel on the landing page
//require_once( get_stylesheet_directory() . '/inc/landingpage_text_area.php'); //Landing page

// ------------- Register Widgets -------------
function register_widgets() {
//  register_widget('JC_Widget_Donate');
}
add_action('widgets_init', 'register_widgets');