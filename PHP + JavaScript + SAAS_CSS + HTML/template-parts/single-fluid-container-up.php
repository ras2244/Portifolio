<?php

	// Template Name: single_fluid_container_up
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

	<!-- first Container (Fluid) -->
	<div class="row">
		<img width="100%" style="padding-bottom: 20px;" src="<?php echo $contentValue['background_img']['url']?>" alt="background img">
	</div>

	<!-- Second container -->
	<div class="container">
		<div class="row">

			<!-- Main middle content -->
			<div class="col-sm-8 col-sm-offset-2">
				<?php
				echo $contentValue['content2'];
				// print_r($contentValue['download_link_repeater']);
					if($contentValue['has_links'] == 1){
						if( have_rows('download_link_repeater') ){

							// loop through the rows of data
						    while ( have_rows('download_link_repeater') ) : the_row();

						    	/** sub fields */
						    	$img = get_sub_field('img');
						    	$header = get_sub_field('header');
								$content = get_sub_field('content');
								$download_link = get_sub_field('download_link');

								echo "
								<table class='table'>
									<tbody>
										<td class='cst-fit'>
											<div style='width:". $img['sizes']['thumbnail-width']."px; height:".$img['sizes']['thumbnail-width']."px'>
												<img  src='".$img['sizes']['thumbnail']."' alt='".$img['title']."' >
											</div>
										</td>
										<td>
											<h3>$header</h3>
											<p>$content</p>
											<a  href='$download_link'><img src='".get_template_directory_uri()."/src/images/icon/download.png' alt='Download-link'></a>
										</td>
									</tbody>
								</table>

								";

						    endwhile;
						}
						echo $contentValue['content3'];
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
