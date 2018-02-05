<?php

	// Template Name: single_container
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


	<div class="container">
		<div class="row">

			<!-- Main middle content -->
			<div class="col-sm-8 col-sm-offset-2">
				<?php
				 // echo $contentValue['content1'] ;
				echo the_content();

				if($contentValue['has_dropdown'] == true){
					$i = 0;
					// loop through sub content dropdown
				    while ( have_rows('dropdown_content_repeater') ) : the_row();

				    	/** sub fields */
				    	$title = get_sub_field('title');
						$content = get_sub_field('content');

						echo "

						<!-- collapsable header title -->
						<div class='row cst-dropdown-content'>
							<div class='col-xs-7'> <h3>$title</h3> </div>
							<div class='col-xs-5 cst-right'> <button class='btn cst-career-btn' type='button' data-toggle='collapse' data-target='#dropContents-".$i."' aria-expanded='false' aria-controls='dropContents-".$i."'>
								  <img src=' ".get_template_directory_uri()."/src/images/icon/more_DD.png' alt='more'>
								</button>
							</div>
						</div>

						<!-- collapsable contents -->
						<div class='row collapse' id='dropContents-".$i."'>
						  <div class='well cst-no-border-radius cst-ul-text'>
						    $content
						  </div>
						</div>

						<!-- empty div for spacing -->
						<div class='cst-margin-b-2'></div>

						";
						$i++;
				    endwhile;
				}

				?>
			</div>

		</div>
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
