<?php 
	
	// Template Name: single_fluid_container_middle
	get_header();
?>

<?php
	 if ( have_posts() ) : while ( have_posts() ) : the_post();

	 	// get all filed contents
		$contentValue = get_fields();

		// echo get_query_var('pagename');

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

	<!-- first Container -->
	<div class="container">
		<div class="row">

			<!-- Main content -->
			<div class="col-sm-8 col-sm-offset-2">
				<?php

					/** print Content 1 here*/ 
					echo $contentValue['content1'];

				?>
			</div>

		</div>
	</div>

	<!-- Second container (fluid) -->
	<div class="row">
		<img width="100%" style="padding-bottom: 30px; padding-top: 20px" src="<?php echo $contentValue['background_img']['url']?>" alt="background img">
	</div> 

	<!-- Third Container -->
	<div class="row <?php //if($contentValue['well_class']=='on') echo 'well';?>">
		<div class="container ">
			<div class="row">
				<div class="col-sm-8 col-sm-offset-2">
					<?php 
						/** print Content 2 here*/ 
						echo $contentValue['content2'];

						if($contentValue['has_column'] == 1){
							if( have_rows('division') ){

							// loop through the rows of data
						    while ( have_rows('division') ) : the_row();

						    	/** sub fields */
						    	$left_col = get_sub_field('left_column');
						    	$right_col = get_sub_field('right_column');

						    	/** print Content repeater rows here*/ 
						    	if(!$right_col){ 

						    		/** echo col-12 if there is no right col content*/
						    		echo "
									<div class='col-sm-12 cst-no-padding'>
										$left_col
									</div>
									";

						    	}else{

						    		/** echo generic col-6 if both (right-left) contents are present*/
						    		echo "
									<div class='col-sm-6 cst-no-padding'>
										$left_col
									</div>
									
									<div class='col-sm-6 cst-no-padding'>
										$right_col
									</div>	
									";
						    	}

						    endwhile;
						}

						/** print Content 3 here*/ 
						echo "
						<div class='col-sm-12 cst-no-padding'>
							$contentValue[content3]
						</div>
						";
						}

					?>
				</div>
			</div>
		</div>
	</div>

	<!-- forth container for background images if there is any -->
	<div class="row">
		<?php 	
			if($contentValue['background_img_2']){
				echo '<img width="100%" src="'.$contentValue['background_img_2']['url'].'" alt="background img two" >';
			}
		?>
		
	</div> 

</div>

<?php endwhile; else: ?>
		<p>Sorry, no posts matched your criteria.</p>
<?php endif; ?>


<?php

	$req_indicies = $contentValue['required_blocks_indices'][0];
	$req_posts = [$req_indicies['first_index'] , $req_indicies['second_index'], $req_indicies['third_index'] ];
	include( locate_template( 'template-parts/content-blocks/content-blocks.php', false, false ) ); 

	get_footer();
?>