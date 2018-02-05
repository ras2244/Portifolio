<?php
/**
 * Template part for displaying posts
 *
 * @link https://codex.wordpress.org/Template_Hierarchy
 *
 * @package Alexa2
 */

?>

<!-- Query category post -->
<?php query_posts('category_name=alexa-frontpage-content-1'); ?>
<?php if(have_posts() ):?>




<!--First part content-->
<div class="row well cst-part-content part-1" >

<!-- display all posts with category  -->
<?php while ( have_posts() ) : the_post(); ?>

<!-- Check for translated posts -->
<?php global $post; if($post_id = pll_get_post($post->ID, pll_current_language())) : ?>

<?php

	  	//get translated post (in current language) if exists
        $post = get_post($post_id);

        //set up the post
        setup_postdata($post);

        //ACF values
        $content_value = get_fields();
?>


	<div class="col-sm-4 cst-content-box">
		<div class="row">

			<div class="col-sm-12">
				<!-- Echo the post contents -->
				<?php echo the_content(); ?>
			</div>
			<div class="col-sm-12">
				<a href="<?php echo $content_value['page_site_link']; ?>"><img src="<?php echo get_template_directory_uri() ?>/src/images/icon/learnMoreBtnContent.png" alt="Learn More"></a>
			</div>
		</div>
	</div>

<?php else: ?>
<!-- if there is no translated content Get static contents -->
<?php // get_template_part('template-parts/landing-page/static_content/content-part-1'); ?>

<!-- End loops -->
<?php endif; ?><!-- end polylang post setup -->
<?php endwhile; ?><!-- end while loop for posting content -->

</div><!-- End Row -->



<?php else: ?>
<!-- Get static contents  -->
<?php  get_template_part('template-parts/landing-page/static_content/content-part-1'); ?>

<?php endif; ?>

<!-- Reset Query -->
<?php wp_reset_query(); ?>




<!-- Query category post & get ACFs values-->
<?php query_posts('category_name=alexa-frontpage-content-1');

	//ACF values
	$content_value = get_fields();



?>
