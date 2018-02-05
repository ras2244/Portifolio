<?php

/**
 * Register custom fonts.
 */
function alexa_fonts_url() {
  $fonts_url = '';
  /*
   * Translators: If there are characters in your language that are not
   * supported by Open Sans, translate this to 'off'. Do not translate
   * into your own language.
   */
  $open_sans = _x( 'on', 'Open Sans font: on or off', 'alexa' );
  if ( 'off' !== $open_sans ) {
    $font_families = array();
    $font_families[] = 'Open Sans:300,400,600,700'; // TODO Update fonts
    $query_args = array(
        'family' => urlencode( implode( '|', $font_families ) ),
        'subset' => urlencode( 'latin,latin-ext' ),
    );
    $fonts_url = add_query_arg( $query_args, 'https://fonts.googleapis.com/css' );
  }
  return esc_url_raw( $fonts_url );
}

/**
 * Add preconnect for Google Fonts.
 *
 * @since alexa 1.0
 *
 * @param array  $urls           URLs to print for resource hints.
 * @param string $relation_type  The relation type the URLs are printed.
 * @return array $urls           URLs to print for resource hints.
 */
function alexa_resource_hints( $urls, $relation_type ) {
  if ( wp_style_is( 'alexa-fonts', 'queue' ) && 'preconnect' === $relation_type ) {
    $urls[] = array(
        'href' => 'https://fonts.gstatic.com',
        'crossorigin',
    );
  }
  return $urls;
}
add_filter( 'wp_resource_hints', 'alexa_resource_hints', 10, 2 );