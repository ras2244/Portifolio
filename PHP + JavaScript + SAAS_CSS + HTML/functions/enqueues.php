<?php

/**
 * Enqueue scripts and styles.
 */

function alexa_scripts() {

  // -------------------- Styles --------------------

  // Add Fonts
  //  wp_enqueue_style( 'alexa-fonts', alexa_fonts_url() );

  // Bootstrap 4.0
  wp_enqueue_style( 'bootstrap_css', '//maxcdn.bootstrapcdn.com/bootstrap/3.3.7/css/bootstrap.min.css' );

  // Font awesome
  wp_enqueue_style( 'font_awesome', 'https://maxcdn.bootstrapcdn.com/font-awesome/4.7.0/css/font-awesome.min.css' );

  // Used for animations
  //wp_enqueue_style( 'animate_css', 'https://cdnjs.cloudflare.com/ajax/libs/animate.css/3.5.2/animate.min.css' );

  // !!--- Must be the last stylesheet ---!!
  wp_enqueue_style( 'alexa-style', get_stylesheet_uri() );  


  // -------------------- Scripts -------------------- //

  // Tether for bootstrap 4.0
 // wp_enqueue_script( 'bootstrap_tether', 'https://cdnjs.cloudflare.com/ajax/libs/tether/1.4.0/js/tether.min.js', array('jquery') );

  // jQuery 3.2.1
  wp_enqueue_script( 'jQuery', get_template_directory_uri() . '/src/bootstrap/js/jquery.min.js' , array('jquery'),'3.2.1',true  );

  wp_enqueue_script( 'javaScriptStd', get_template_directory_uri() . '/src/js/helpers/javascriptAlt.js', array('jquery'),'3.3.7',true  );

  // Bootstrap JS 3.3.7 
  wp_enqueue_script( 'bootstrap_js', get_template_directory_uri() . '/src/bootstrap/js/bootstrap.min.js' , array('jquery'),'3.3.7',true  );
 
  wp_enqueue_script( 'alexa-skip-link-focus-fix', get_template_directory_uri() . '/src/js/skip-link-focus-fix.js', array(), '20151215', true );

  // Bootstrap JS 3.3.7 alert
  wp_enqueue_script( 'bootstrap_js_alert', get_template_directory_uri() . '/src/bootstrap/js/alert.js' , array('jquery'),'3.3.7' ,true  );

  // Bootstrap JS 3.3.7 modal
  wp_enqueue_script( 'bootstrap_js_modal', get_template_directory_uri() . '/src/bootstrap/js/modal.js' , array('jquery'),'3.3.7', true  );

  // Bootstrap JS 3.3.7 dropdown
  wp_enqueue_script( 'bootstrap_js_dropdown', get_template_directory_uri() . '/src/bootstrap/js/dropdown.js' , array('jquery'),'3.3.7', true  );

  // Bootstrap JS 3.3.7 scrollspy
  wp_enqueue_script( 'bootstrap_js_scrollspy', get_template_directory_uri() . '/src/bootstrap/js/scrollspy.js' , array('jquery'),'3.3.7', true  );

  // Bootstrap JS 3.3.7 tab
  wp_enqueue_script( 'bootstrap_js_tab', get_template_directory_uri() . '/src/bootstrap/js/tab.js' , array('jquery'),'3.3.7', true  );

  // Bootstrap JS 3.3.7 tooltip
  wp_enqueue_script( 'bootstrap_js_tooltip', get_template_directory_uri() . '/src/bootstrap/js/tooltip.js' , array('jquery'),'3.3.7',true  );

  // Bootstrap JS 3.3.7 popover
  wp_enqueue_script( 'bootstrap_js_popover', get_template_directory_uri() . '/src/bootstrap/js/popover.js' , array('jquery'),'3.3.7', true );

// Bootstrap JS 3.3.7 button
  wp_enqueue_script( 'bootstrap_js_button', get_template_directory_uri() . '/src/bootstrap/js/button.js' , array('jquery'),'3.3.7', true );

  // Bootstrap JS 3.3.7 collapse
  wp_enqueue_script( 'bootstrap_js_collapse', get_template_directory_uri() . '/src/bootstrap/js/collapse.js' , array('jquery'),'3.3.7', true );

  // Bootstrap JS 3.3.7 carousel
  wp_enqueue_script( 'bootstrap_js_carousel', get_template_directory_uri() . '/src/bootstrap/js/carousel.js' , array('jquery'),'3.3.7', true );

  // wp_enqueue_script( 'alexa-navigation', get_template_directory_uri() . '/src/js/navigation.js', array(), '20151215', true );

  // wp_enqueue_script( 'alexa-skip-link-focus-fix', get_template_directory_uri() . '/src/js/skip-link-focus-fix.js', array(), '20151215', true );

  wp_enqueue_script( 'scroll_reveal', get_template_directory_uri() . '/src/js/lib/scrollreveal.min.js', array('jquery'),'3.3.7', true );

  //alexa js 
  wp_enqueue_script( 'alexa_js', get_template_directory_uri() . '/src/js/alexa_cst.js' , array('jquery'), '20170918', true ); 

  if ( is_singular() && comments_open() && get_option( 'thread_comments' ) ) {
    wp_enqueue_script( 'comment-reply' );
  }
}
add_action( 'wp_enqueue_scripts', 'alexa_scripts');
