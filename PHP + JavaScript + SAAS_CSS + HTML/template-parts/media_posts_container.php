<?php 
	
	// Template Name: media_posts_container
	get_header();
?>
	
<?php
	 if ( have_posts() ) : while ( have_posts() ) : the_post();

	 	// get all filed contents
		$contentValue = get_fields();
		// echo $contentValue['content1']
		?>
				<!-- name as ID for CSS styling  -->
<div id="_page-<?php echo get_query_var('pagename');?>">

<!-- header title for mobile view -->
<?php

/** if there is a mobile head set */
if($contentValue['has_mobile_header_title'] == true){

	/**
	* gets the post_id of the page
	* Retrieves ACF values set in that page
	*/
	$mobile_post_id =  get_field('select_mobile_header_page', false, false);
	$parent_title = get_field('parent_page_title', $mobile_post_id);
	$page_link_repeater = get_field('MHT_content_repeater', $mobile_post_id);

echo "
	<div  id='page_header_title' class='conatiner cst-mobile-hidden'>
		<div class='row'>
			<div class='col-xs-6'> <h3>$parent_title</h3> </div>
			<div class='col-xs-6 cst-right'> <button type='button' class='navbar-toggle collapsed' data-toggle='collapse' data-target='#test_col' aria-expanded='false'><span class='glyphicon glyphicon-plus'></span></button>
			</div>
		</div>
		<div id='test_col'  class='collapse navbar-collapse'>
";
	
	/** echo out the data from repeater*/
	while ( have_rows('MHT_content_repeater' , $mobile_post_id) ) : the_row();

    	/** 
		* get_sub_field() with the 'false' parameter returns post ID
		* Using the post ID, get_the_title gives the title
    	*/
    	$title = get_the_title(get_sub_field('page_link', false, false));
		$link = get_the_permalink(get_sub_field('page_link', false, false));
		
		//print the sub fields within a div-'row'
		echo "
		<div class='row'>
			<a href='$link'><h3>$title</h3></a>
		</div>
		";
    endwhile;

echo"
		</div>
	</div>";
}
	
?>
	<!-- Query category post -->
	<?php query_posts('category_name=alexa-media-posts'); ?>

	<!-- Check for posts -->
	<?php if ( have_posts() ) : ?>

	<!-- display divider image -->
	<div class="row">
		<img width="100%" src="<?php echo get_template_directory_uri()?>/src/images/icon/Divider.png" alt="divider img">
	</div> 

	<!-- display all posts with category  -->
	<?php while ( have_posts() ) : the_post(); ?>

	<!-- Check for translated posts -->
	<?php global $post; if($post_id = pll_get_post($post->ID, pll_current_language())) : ?> 

	<!-- get ACFs of post and setup translated posts-->
	<?php 
		
		//get translated post (in current language) if exists
        $post = get_post($post_id);

        //set up the post 
        setup_postdata($post);

		$content_post = get_fields();

	?>

	<!-- Post container -->
	<div class="row <?php if($content_post["well_class_media"] == true){ echo "well"; }?>" id="post-<?php the_ID(); ?>">
		<div class="container">
			<div class="row">

				<!-- Main middle content -->
				<div class="col-sm-8 col-sm-offset-2">
					<?php the_content(); ?>
				</div>
				<div class="col-sm-8 col-sm-offset-2 cst-left">
					<a href="<?php echo $content_post['page_site_link']?>"><img src="<?php echo get_template_directory_uri()?>/src/images/icon/readMore.png" alt="Read More"></a>
				</div>

			</div>
		</div>
	</div>

	<!-- display divider image -->
	<div class="row">
		<img width="100%"  src="<?php echo get_template_directory_uri()?>/src/images/icon/Divider.png" alt="divider img">
	</div>
	   
	<!-- End loops -->
	<?php endif; ?><!-- end polylang post setup -->
	<?php endwhile; endif; ?>

	<!-- Reset Query -->
	<?php wp_reset_query(); ?>
	

</div>

<?php
endwhile; else: 
?>
	<p>Sorry, no posts matched your criteria.</p>
<?php endif; ?>

<?php

	$req_indicies = $contentValue['required_blocks_indices'][0];
	$req_posts = [$req_indicies['first_index'] , $req_indicies['second_index'], $req_indicies['third_index'] ];
	include( locate_template( 'template-parts/content-blocks/content-blocks.php', false, false ) ); 

	get_footer();
?>