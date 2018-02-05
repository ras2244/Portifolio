<?php
  /**
   * The header for our theme
   *
   * This is the template that displays all of the <head> section and everything up until <div id="content">
   *
   * @link https://developer.wordpress.org/themes/basics/template-files/#template-partials
   *
   * @package Alexa2
   */
?>
<!DOCTYPE html>
<html <?php language_attributes(); ?>>
  <head>
    <meta charset="utf-8">
    <title>Alexa Translation</title>
    <meta charset="<?php bloginfo( 'charset' ); ?>">
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <link rel="profile" href="http://gmpg.org/xfn/11">
    <?php 
      wp_head();
    ?>

     <style type="text/css">
      <?php 

//         Different styling on the menu depending on the language loaded
        if(pll_current_language("slug") == "fr"){
          echo '
            @media (max-width: 1400px) {

              .cst-sub-menu{
                position: static;
                float: none;
                width: auto;
                margin-top: 0;
                background-color: transparent;
                border: 0;
                -webkit-box-shadow: none;
                box-shadow: none;
              }

              .navbar-header {
                  float: none;
              }
              .navbar-toggle {
                  display: block;
              }
              .navbar-collapse {
                  border-top: 1px solid transparent;
                  box-shadow: inset 0 1px 0 rgba(255,255,255,0.1);
              }
              .navbar-collapse.collapse {
                  display: none!important;
              }
              .navbar-nav {
                  float: none!important;
                  margin: 7.5px -15px;
              }
              .navbar-nav>li {
                  float: none;
              }
              .navbar-nav>li>a {
                  padding-top: 10px;
                  padding-bottom: 10px;
              }
              .navbar-text {
                  float: none;
                  margin: 15px 0;
              }
              /* since 3.1.0 */
              .navbar-collapse.collapse.in { 
                  display: block!important;
              }
              .collapsing {
                  overflow: hidden!important;
              }
          }
          ';
        }else{
          echo '
            @media (max-width: 1214px) {
              .cst-sub-menu{
                position: static;
                float: none;
                width: auto;
                margin-top: 0;
                background-color: transparent;
                border: 0;
                -webkit-box-shadow: none;
                box-shadow: none;
              }

              .navbar-header {
                  float: none;
              }
              .navbar-toggle {
                  display: block;
              }
              .navbar-collapse {
                  border-top: 1px solid transparent;
                  box-shadow: inset 0 1px 0 rgba(255,255,255,0.1);
              }
              .navbar-collapse.collapse {
                  display: none!important;
              }
              .navbar-nav {
                  float: none!important;
                  margin: 7.5px -15px;
              }
              .navbar-nav>li {
                  float: none;
              }
              .navbar-nav>li>a {
                  padding-top: 10px;
                  padding-bottom: 10px;
              }
              .navbar-text {
                  float: none;
                  margin: 15px 0;
              }
              /* since 3.1.0 */
              .navbar-collapse.collapse.in { 
                  display: block!important;
              }
              .collapsing {
                  overflow: hidden!important;
              }
          }

          ';
        }
      ?>
    </style>
  </head>

  <body <?php body_class(); ?>>
    <div id="page" class="site">

      <a class="skip-link screen-reader-text" href="#content"><?php esc_html_e( 'Skip to content', 'alexa' ); ?></a>

      <header id="masthead" class="site-header">
        <nav class="navbar navbar-default cst-header" id="alexa_main_nav">
          <div class="container-fluid">

            <!-- Search row -->

            <div class="collapse navbar-collapse" id="search-from-container" style="padding-bottom: 10px; padding-top: 10px ">
              <div class="col-sm-offset-8 col-sm-4">
                <form id="search-bar" role="search" method="get" class="search-form" action="<?php echo home_url( '/' ); ?>">

                  <div class="row">
                    <div class="col-xs-11 cst-no-padding">

                      <!-- Input search -->
                      <!-- <label for="s">Search</label> -->
                      <input type="text" value="<?php echo get_search_query(); ?>" name="s" class="cst-search-bar">

                      <!-- Input submit btn -->
                      <input type="submit" value=" " class="cst-form-submit" id="searchSubmit" style="background: url('<?php echo get_template_directory_uri(); ?>/src/images/icon/search.png');">

                    </div>
                    <div class="col-sx-11">
                    <!-- Language choices -->
                      <a id="en-link" class="link_lang" href="<?php echo pll_the_languages(array('raw'=>1, ))['en']['url']; ?>" >EN</a>
                      <a id="fr-link" class="link_lang" href="<?php echo pll_the_languages(array('raw'=>1, ))['fr']['url']; ?>" >FR</a> 

                      <!-- For PHP V less than 7 -->
                      <!-- <a id="en-link" class="link_lang" href="<?php //echo pll_home_url( 'en' ); ?>" >EN</a>
                      <a id="fr-link" class="link_lang" href="<?php // echo pll_home_url( 'fr' ); ?>" >FR</a> -->

                  </div>
                  </div>
                </form>
              </div>
            </div>

            <!-- Main nav content -->

                <!-- Brand and toggle get grouped for better mobile display -->
                <div class="navbar-header" id="navbar-header">
                    <!-- <button class="menu-toggle" aria-controls="primary-menu" aria-expanded="false"><?php esc_html_e( 'Primary Menu', 'alexa' ); ?></button>
                     -->

                     <!-- Toggle menu button @media size -->
                    <button id="nav_button" type="button" class="navbar-toggle collapsed" data-toggle="collapse" data-target="#bs-example-navbar-collapse-1" aria-expanded="false">
                      <span class="sr-only">Toggle navigation</span>
                      <span class="icon-bar"></span>
                      <span class="icon-bar"></span>
                      <span class="icon-bar"></span>
                       <span class="icon-bar"></span>
                    </button>

                    <!-- Alexa Logo -->
                    <?php theme_prefix_the_custom_logo();  ?>

                    <!-- Toggle search button @media size -->
                    <button type="button" id="search-btn-toggle" class="navbar-toggle collapsed cst-no-padding" data-toggle="collapse" data-target="#search-from-container" aria-expanded="false">
                      <span class="sr-only">Toggle navigation</span>
                      <img src="<?php echo get_template_directory_uri(); ?>/src/images/icon/search.png">
                    </button>

                    <div id="langDiv" class="">
                      <!-- toggle from JS -->
                    </div>
                    
                </div>

                <!-- Collect the nav links, forms, and other content for toggling -->

                <?php
                  // Print out custom nav menus
                  wp_nav_menu( array(
                    'theme_location' => 'menu-1',
                    'menu_name'        => 'alexa_menu',
                    'menu_class' => 'nav navbar-nav cst-menu-list',
                    'menu_id' => 'alexa-nav',
                    'container_class' => 'collapse navbar-collapse',
                    'container_id' => 'bs-example-navbar-collapse-1'

                  ) );
                ?><!-- /.navbar-collapse -->


          </div><!-- /.container-fluid -->
        </nav>

      </header>

    </div>

    <!-- Entire body container start  -->
    <div id="content" class="container-fluid">