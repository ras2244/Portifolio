
      <footer  id="colophon" class="site-footer">
        <div class="site-info">
                <div class="row cst-footer" style="background-image: url(' <?php echo get_template_directory_uri();?>/src/images/icon/footerPattern.png ')">

                    <!-- 1st division -->
                    <div class="col-sm-4 cst-footer-box first-footer-box">

                        <!-- Query category post -->
                        <?php query_posts('category_name=alexa-footer-left'); ?>

                        <?php if(have_posts() ):?>

                        <!-- display all posts with category  -->
                        <?php while ( have_posts() ) : the_post(); ?>

                        <!-- Check for translated posts -->
                        <?php global $post; if($post_id = pll_get_post($post->ID, pll_current_language())) : ?>

                        <?php

                                //get translated post (in current language) if exists
                                $post = get_post($post_id);

                                //set up the post
                                setup_postdata($post);
                        ?>

                        <div class="col-sm-12">
                            <?php echo the_content(); ?>
                        </div>

                        <?php else:?>
                        <!-- If there is no content found via POST; print this out -->
                        <div class="col-sm-12">
                            <p class="cst-footer-header"><b>TO</b></p>
                            <p class="cst-footer-text">120 Eglinton Avenue East, Suite 1100</br>
                            Toronto, Ontario M4P 1E2</br>
                            Canada</p>
                        </div>
                        <div class="col-sm-12">
                            <p class="cst-footer-header"><b>MTL</b></p>
                            <p class="cst-footer-text">1000 Rue de la Gauchetiere Ouest, 24e etage</br>
                            Montreal (Quebec) H3B 4WB</br>
                            Canada</p>
                        </div>
                        <div class="col-sm-12">
                            <p class="cst-footer-header"><b>NYC</b></p>
                            <p class="cst-footer-text">245 Park Avenue, 39th Floor</br>
                            Manhattan, New York 10167</br>
                            U.S.A.</p>
                        </div>

                        <!-- End loops -->
                        <?php endif; ?><!-- end polylang post setup -->

                        <?php endwhile; ?><!-- end while loop for posting content -->

                        <?php else:?>
                        <!-- If there is no content found via POST; print this out -->
                        <div class="col-sm-12">
                            <p class="cst-footer-header"><b>TO</b></p>
                            <p class="cst-footer-text">120 Eglinton Avenue East, Suite 1100</br>
                            Toronto, Ontario M4P 1E2</br>
                            Canada</p>
                        </div>
                        <div class="col-sm-12">
                            <p class="cst-footer-header"><b>MTL</b></p>
                            <p class="cst-footer-text">1000 Rue de la Gauchetiere Ouest, 24e etage</br>
                            Montreal (Quebec) H3B 4WB</br>
                            Canada</p>
                        </div>
                        <div class="col-sm-12">
                            <p class="cst-footer-header"><b>NYC</b></p>
                            <p class="cst-footer-text">245 Park Avenue, 39th Floor</br>
                            Manhattan, New York 10167</br>
                            U.S.A.</p>
                        </div>

                        <?php endif; ?>

                        <!-- Reset Query -->
                        <?php wp_reset_query(); ?>


                    </div>

                    <!-- 2nd division -->
                    <div class="col-sm-4 cst-footer-box cst-border-left-right">
                        <div class="col-sm-12">
                            <p class="cst-footer-header"><span id="subscribe_LANG">SUBSCRIBE TO OUR NEWSLETTER:</span></p>
                            <input type="hidden" id="defaultDirectoryUri" value="<?php echo get_template_directory_uri() ?>">
                            <form id="signUpForm" class="search-form">
                                <div class="col-sm-12">
                                    <div id="sub_form_success" class="alert alert-success cst-no-margin cst-hidden">
                                        <!-- Close button -->
                                        <a href="#" class="close" onclick="hideElement(event, this)" aria-label="close">&times;</a>
                                        <div><!-- Content Filled via ajax --></div>

                                    </div>
                                    <div id="sub_form_error" class="alert alert-danger cst-no-margin cst-hidden">
                                        <!-- Close Button -->
                                        <a href="#" class="close" onclick="hideElement(event, this)" aria-label="close">&times;</a>
                                        <div><!-- Content Filled via ajax --></div>
                                    </div>
                                </div>
                                <div class="col-sm-12 cst-no-left-padding">
                                    <div class="col-sm-2 cst-no-padding">
                                        <label for="signupName"><span id="name_LANG">Name:</span></label>
                                    </div>
                                    <div class="col-sm-10 cst-no-padding">
                                        <input type="text" name="signupName"  id="signupName" class="cst-transparent" placeholder="name" required>
                                    </div>
                                </div>
                                <div class="col-sm-12 cst-no-left-padding">
                                    <div class="col-sm-2 cst-no-padding">
                                        <label for="signupEmail"><span id="email_LANG">Email:</span></label>
                                    </div>
                                    <div class="col-sm-10 cst-no-padding">
                                        <input type="email" name="signupEmail" id="signupEmail" class="cst-transparent" placeholder="Email" required>
                                    </div>
                                </div>
                                <div class="col-sm-12" style="text-align:right">
                                    <input type="submit" value="_" class="cst-form-submit" id="signupSubmit" style="background: url('<?php echo get_template_directory_uri(); ?>/src/images/icon/subButton.png');">
                                </div>
                            </form>
                        </div>
                        <div class="col-sm-12" id="footerStampLogo">

                            <div class="col-xs-4">
                                <img src="<?php echo get_template_directory_uri(); ?>/src/images/icon/stamp1.png" alt="stamp1">
                            </div>
                            <div class="col-xs-4">
                                <img src="<?php echo get_template_directory_uri(); ?>/src/images/icon/stamp2.png" alt="stamp2">
                            </div>
                            <div class="col-xs-4">
                                <!-- Empty div for spacing -->
                            </div>
                        </div>
                        <div class="col-sm-12">
                            <p><span id="copy_LANG">Copyright 2017 Alexa Translations. All rights reserved.</span> </br>
                            <a href="<?php echo get_page_link( get_page_by_title( "TERMS AND CONDITIONS" )->ID ); ?>" class="cst-link-white">Terms &amp; Conditions</a> | <a href="<?php echo get_page_link( get_page_by_title( "PRIVACY POLICY" )->ID ); ?>" class="cst-link-white">Privacy Policy</a></p>
                        </div>
                    </div>

                    <!-- 3rd division -->
                    <div class="col-sm-4 cst-footer-box">
                        <div class="row">

                        <!-- Query category post -->
                        <?php query_posts('category_name=alexa-footer-right'); ?>

                        <?php if(have_posts() ):?>


                        <!-- display all posts with category  -->
                        <?php while ( have_posts() ) : the_post(); ?>

                        <!-- Check for translated posts -->
                        <?php global $post; if($post_id = pll_get_post($post->ID, pll_current_language())) : ?>

                        <?php

                                //get translated post (in current language) if exists
                                $post = get_post($post_id);

                                //set up the post
                                setup_postdata($post);
                        ?>

                        <div class="col-sm-12 foot-contact-us">
                            <?php echo the_content(); ?>
                        </div>

                        <!-- Social media link repeater ACF -->
                        <?php $acf_content = get_fields(); ?>

                        <div class="col-sm-12" style="padding-top: 50px">
                            <p class="cst-footer-header"><span id="connect_lang">CONNECT WITH US:</span></p>
                            <span id="socialButton">
                                <?php if(have_rows('social_link_repeater')):?>

                                <?php while ( have_rows('social_link_repeater') ) : the_row();?>

                                <?php
                                    //get logo and link from repeater into variables
                                    $logo = get_sub_field('logo_upload');
                                    $url = get_sub_field('social_media_url');
                                    // print_r($logo['title']);
                                ?>
                                    <a href="<?php echo $url;?>" target="_blank">
                                        <img src="<?php echo $logo['url']; ?>" alt="<?php echo $logo['title'] ?> ">
                                    </a>

                                <?php endwhile;?><!-- end ACF repeater while loop-->

                                <?php endif; ?>

                            </span>
                        </div>

                        <div class="col-sm-12 foot-career" style="padding-top:50px"   >
                            <!-- <p class="cst-footer-header">CAREERS</p> -->
                            <p class="cst-footer-text"><?php echo $acf_content['content_3']?></p>
                        </div>


                        <?php else: ?>

                        <!-- if NO CONTENT print out this static content-->
                        <div class="col-sm-12">
                            <p class="cst-footer-header">CONNECT WITH US:</p>
                            <span id="socialButton">
                                <a href="https://www.facebook.com/Alexa-Translations-360162825350/" target="_blank">
                                    <img src="<?php echo get_template_directory_uri(); ?>/src/images/icon/facebook.png" alt="facebook">
                                </a>
                                <a href="https://twitter.com/alexatranslate" target="_blank">
                                    <img src="<?php echo get_template_directory_uri(); ?>/src/images/icon/twitter.png" alt="twitter">
                                </a>
                                <a href="https://www.linkedin.com/company/alexa-translations/" target="_blank">
                                    <img src="<?php echo get_template_directory_uri(); ?>/src/images/icon/instagram.png" alt="linkedin">
                                </a>
                            </span>
                        </div>

                        <div class="col-sm-12">
                            <p class="cst-footer-header">CONTACT US:SS</p>
                            <p class="cst-footer-text">T: 1-877-452-5224 | F: 1-888-301-0607</br>
                            E: <a href="#" class="cst-link-white">info@alexatranslation.com</a></p>
                        </div>



                        <div class="col-sm-12" style="padding-top:30px">
                            <p class="cst-footer-header">CAREERS:</p>
                            <p class="cst-footer-text">We want to hear from you <a href="<?php echo get_page_link( get_page_by_title( "CAREER" )->ID ); ?>" class="cst-link-white">Contact us today</a>.</p>
                        </div>


                        <!-- End loops -->
                        <?php endif; ?><!-- end polylang post setup -->
                        <?php endwhile; ?><!-- end while loop for posting content -->

                        <?php else: ?>

                        <!-- if NO CONTENT print out this static content-->
                        <div class="col-sm-12">
                            <p class="cst-footer-header">CONNECT WITH US</p>
                            <span id="socialButton">
                                <a href="#face" target="_blank">
                                    <img src="<?php echo get_template_directory_uri(); ?>/src/images/icon/facebook.png" alt="facebook">
                                </a>
                                <a href="#twit" target="_blank">
                                    <img src="<?php echo get_template_directory_uri(); ?>/src/images/icon/twitter.png" alt="twitter">
                                </a>
                                <a href="#insta" target="_blank">
                                    <img src="<?php echo get_template_directory_uri(); ?>/src/images/icon/instagram.png" alt="linkedin">
                                </a>
                            </span>
                        </div>

                        <div class="col-sm-12">
                            <p class="cst-footer-header">CONTACT US</p>
                            <p class="cst-footer-text">T: 1-877-452-5224 | F: 1-888-301-0607</br>
                            E: <a href="#" class="cst-link-white">info@alexatranslation.com</a></p>
                        </div>



                        <div class="col-sm-12" style="padding-top:30px">
                            <p class="cst-footer-header">CAREERS</p>
                            <p class="cst-footer-text">We want to hear from you <a href="<?php echo get_page_link( get_page_by_title( "CAREER" )->ID ); ?>" class="cst-link-white">Contact us today</a>.</p>
                        </div>



                        <?php endif; ?>
                        </div>
                        <!-- Reset Query -->
                        <?php wp_reset_query(); ?>

                    </div>
                </div>

        </div>
      </footer>

        <?php
        wp_footer();
        ?>

    </div> <!-- /container from header.php-->

  </body>
</html>
