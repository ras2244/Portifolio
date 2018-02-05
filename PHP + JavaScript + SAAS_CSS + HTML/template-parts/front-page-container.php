<?php
	//Template name: front_page_template
?>

<?php $contentValue = get_fields(); ?>

<?php if ( have_posts() ) : while ( have_posts() ) : the_post(); ?>

	<!-- Carousel -->
	<?php 
		if($contentValue['']){

		}
	?>

<?php endwhile; endif;?>