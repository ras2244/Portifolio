<?php
	/**
	*	This file gets its content from a post name 'alexa-frontpage-slideshow'
	*/

?>

<!-- This styling is for testing purpose and will be removed -->
<style type="text/css">

	@media screen and (max-width: 800){
	#mainCarouselContainer{
		margin-bottom: 50% !important;
	}
}
</style>

	<!-- Query category post -->
	<?php query_posts('category_name=alexa-frontpage-slideshow'); ?>

	<!-- Check for posts -->
	<?php if ( have_posts() ) : ?>

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


	<!-- get ACFs of post -->
	<?php $i=0; //counter ?>


	<!-- Carousel -->
<div class="row" id="mainCarouselContainer" style="">
	<div id="mainCarousel" class="carousel slide" data-ride="carousel">

	  <!-- Wrapper for slides -->
	  <div class="carousel-inner" id="carousel-items">

	<?php 
		
		/** get repeater and its content */
		while ( have_rows('front_page_slideshow') ) : the_row();?>
		<?php

	    	/** 
			* get_sub_field() with the 'false' parameter returns post ID
			* Using the post ID, get_the_title gives the title
	    	*/
	    	$headline = get_sub_field('headline');
			$img = get_sub_field('image');
			$link = get_sub_field('slideshow_page_link');
			
		?>

		<!-- slideshows -->
		<div class="item <?php if($i == 0){ echo "active";}?>" >
	      	<img style="" src="<?php echo  $img['url']; ?>" alt="slideshow-<?php echo $i ?>">
	      	<div class="carousel-caption">
				<div class="container-fluid">
					<!-- check if counter is even or not -->
					<div class="row <?php if($i % 2 == 0){ echo "cst-right";}else{ echo "cst-left";} ?>">
						<div  class="col-sm-12 cst-slideshow-content">
<!-- 							<p class="cst-carousel-title" -->
								<?php echo $headline; ?>
								<!-- Communicating in a <br>  multilingual economy -->
							<!-- </p> -->
						</div>
						<div class="col-xs-12">
							<a class="cst-carousel-btn" href="<?php echo $link; ?>"><img src="<?php echo get_template_directory_uri(); ?>/src/images/icon/learnMoreBtn.png" alt="learn more"></a>
						</div>
					</div>
				</div>	
			</div>
	    </div>

	    <?php $i++; ?>

		<!-- end ACF's repeater loop -->
		<?php endwhile; ?>
	   
		</div><!-- end of slide wrapper -->

		  <!-- Left and right controls -->
		  <a class="left carousel-control" href="#mainCarousel" data-slide="prev">
		  	<span class="carousel-control-prev-icon" aria-hidden="true"></span>
		    <span class="sr-only">Previous</span>

		  </a>
		  <a class="right carousel-control" href="#mainCarousel" data-slide="next">
		  	<span class="carousel-control-next-icon" aria-hidden="true"></span>
		    <span class="sr-only">Next</span>
		  </a>

		  <!-- Indicators -->
		  <div class="row" style="margin:0px">
			<div class="col-sm-offset-9 col-sm-3" style="text-align: right; bottom: 20px">
			  <ol class="carousel-indicators" style="top: 26px;">
			  	<?php $i=0; while ( have_rows('front_page_slideshow') ) : the_row(); ?>
			  		<li data-target="#mainCarousel" data-slide-to="<?php echo $i; ?> " class="<?php if($i == 0){ echo "active";}?>"></li>
			  		<?php $i++; ?>
			  	<?php endwhile;?>
			  </ol>
			</div>
		 </div>

		</div>
	</div>



	<!-- End loops -->
<?php endif; ?><!-- end polylang POST setup -->
	<?php endwhile; ?><!-- end while loop to display content -->

<?php else: ?>
<!-- Get static contents  -->
<?php  get_template_part('template-parts/landing-page/static_content/carousel'); ?>

<?php endif; ?>

	<!-- Reset Query -->
	<?php wp_reset_query(); ?>
