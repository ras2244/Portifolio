<?php
	/**
	* ------------------READ ME------------------------
	*	This template is responsible to print out "Content Blocks" as shown in the front page.
	*
	*	----------How It Works----------
	*	Every page that needs the content blocks should call this template page and add a variable
	*	called '$req_post = []'. This vairable will contain the index values of what needs to be printed out.
	*	
	*	Example:- 
	* 	Language Pages needs 'TRANSLATION' , 'CULTURAL CONSULTING' and 'CHOOSE ALEXA'.
	* 	For each of these blocks the indecies are 4, 1, 2 respectively.
	*	So the variable would be $req_post[4, 1, 2]
	* 	These indicies are slected directly from WordPress
	*/
?>

<!-- Query category post -->
<?php 
	$query = new WP_Query( array(

		    'tax_query' => array(
		        array(
		            'taxonomy' => 'category',
		            'field' => 'slug',
		            'terms' => array( 'alexa-frontpage-content-1', 'alexa-frontpage-content-2', 'alexa-content-blocks' )
		        )
		    )
		)
	);

	// print out all posts for debugging reasons. Comment the echo out.
	for($i = 0; $i < count($query->posts); $i++ ){
		//echo $query->posts[$i]->post_content;
	}

?>

<?php if(have_posts() ):?>



	<!-- Parent div -->
	<div class="row well cst-part-content part-1 content-block-line" >

	<!-- display all posts with category  -->
	<?php for($i = 0; $i < 3 ; $i++ ): ?>

		<!-- Check for translated posts -->
		<?php  $post = $query->posts[$req_posts[$i]]; if($post_id = pll_get_post($post->ID, pll_current_language())) : ?>

		<!-- get and set up posts to languages -->
		<?php

			  	//get translated post (in current language) if exists
		        $post = get_post($post_id);

		        //set up the post
		        setup_postdata($post);

		        //ACF values
		        $content_value = get_fields();
		?>

		<!-- Display Contents -->
		<div class="col-sm-4 cst-content-box">
			<div class="row">

				<div class="col-sm-12 <?php if($req_posts[$i] == 1){ echo 'choose-alexa-post'; }?>">
					<!-- Echo the post contents -->
					<?php echo the_content(); ?>
				</div>
				<div class="col-sm-12">
					<a href="<?php echo $content_value['page_site_link']; ?>"><img src="<?php echo get_template_directory_uri() ?>/src/images/icon/learnMoreBtnContent.png" alt="Learn More"></a>
				</div>
			</div>
		</div>
		

		<!-- End loops -->
		<?php endif; ?><!-- end polylang post setup -->
	<?php endfor; ?><!-- end for loop for posting content -->

	</div><!-- End Parent Div-->


<?php endif; ?>
<!-- Reset Query -->
<?php wp_reset_query(); ?>