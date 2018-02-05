<?php
/**
 * Template part for displaying results in search pages
 *
 * @link https://codex.wordpress.org/Template_Hierarchy
 *
 * @package Alexa2
 */
	//get ACFS within page/posts
	$content_post = get_fields();
?>

<article id="post-<?php the_ID(); ?>" <?php post_class(); ?>>
	<header class="entry-header">

			<?php
			// the_title( sprintf( '<h2 class="entry-title"><a href="%s" rel="bookmark">', esc_url( get_permalink() ) ), '</a></h2>' ); 
			$cat = get_the_category();
			//only allow pages and posts category with alexa-media-posts slugs 
			if ( 'post' !== get_post_type() || $cat[0]->slug === 'alexa-media-posts' ){

				//if alexa media post then redirect to media page
				if($cat[0]->slug === 'alexa-media-posts'){

					//attach the post id to link 
					the_title( sprintf( '<h2 class="entry-title"><a href="%s" rel="bookmark">', esc_url( get_page_link( get_page_by_title( "MEDIA" )->ID ) ). '#post-'.get_post()->ID ), '</a></h2>' ); 
				}else{
					the_title( sprintf( '<h2 class="entry-title"><a href="%s" rel="bookmark">', esc_url( get_permalink() ) ), '</a></h2>' ); 
				}

				if($content_post['content1'] == ''){
					echo $content_post['content2'];
				}else{
					echo $content_post['content1'];
				}
			}
				
				// print_r($content_post);
			?>
			<!-- <hr class="hr"> -->
		<?php if ( 'post' === get_post_type() ) : ?>
		<div class="entry-meta">
			<!-- <?php alexa_posted_on(); ?> -->
		</div><!-- .entry-meta -->
		<?php endif; ?>
	</header><!-- .entry-header -->

	<div class="entry-summary">
		<?php the_excerpt(); ?>
	</div><!-- .entry-summary -->

	<footer class="entry-footer">
		<!-- <?php alexa_entry_footer(); ?> -->
	</footer><!-- .entry-footer -->
</article><!-- #post-<?php the_ID(); ?> -->
