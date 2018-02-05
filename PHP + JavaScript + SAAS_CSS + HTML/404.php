<?php
/**
 * The template for displaying 404 pages (not found)
 *
 * @link https://codex.wordpress.org/Creating_an_Error_404_Page
 *
 * @package Alexa2
 */

get_header(); ?>

	<div id="primary" class="content-area" class="container">
		<div class="row">
			<main id="main" class="site-main">
				<div class="col-sm-8 col-sm-offset-2">
					<section class="error-404 not-found">
						<header class="page-header">
							<h1 class="page-title"><?php esc_html_e( 'Oops! That page can&rsquo;t be found.', 'alexa' ); ?></h1>
						</header><!-- .page-header -->

						<div class="page-content">
							
							<p><?php esc_html_e( 'If you entered a web address please check if it was correct.', 'alexa' ); ?></p>

							<p id="ins_margin"><?php esc_html_e( 'or', 'alexa' ); ?></p>

							<P><a href="<?php echo get_home_url()?>">Back Home Page!</a></P> 
							

							<?php

								get_home_url();
								// get_search_form();

								// the_widget( 'WP_Widget_Recent_Posts' );
							?>

							<!-- <div class="widget widget_categories">
								<h2 class="widget-title"><?php esc_html_e( 'Most Used Categories', 'alexa' ); ?></h2>
								<ul>
								<?php
									wp_list_categories( array(
										'orderby'    => 'count',
										'order'      => 'DESC',
										'show_count' => 1,
										'title_li'   => '',
										'number'     => 10,
									) );
								?>
								</ul>
							</div><!-- .widget -->

							<!-- <?php

								/* translators: %1$s: smiley */
								$archive_content = '<p>' . sprintf( esc_html__( 'Try looking in the monthly archives. %1$s', 'alexa' ), convert_smilies( ':)' ) ) . '</p>';
								the_widget( 'WP_Widget_Archives', 'dropdown=1', "after_title=</h2>$archive_content" );

								the_widget( 'WP_Widget_Tag_Cloud' );
							?> -->

							</div><!-- .page-content -->
					</section><!-- .error-404 -->
				</div><!-- class col-sm-8 col-sm-offset-2 -->
			</main><!-- #main -->
		</div><!-- class row -->
	</div><!-- #primary -->

<?php
get_footer();
