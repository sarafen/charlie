<?php get_header(); ?>

<body id="blog">


<h1><a href="/" id="logo">Stephen Creates</a></h1>

<?php get_partial('menu'); ?>
 
<section id="main-content">

	<h1>Blog Posts</h1>
	
	
	<?php looper('blog'); ?>
	
	
</section>







<footer role="contentinfo">
<p>Created by Stephen Lovell</p>

<!-- <p>&copy; 2012</p> -->

</footer>


<script src="http://ajax.googleapis.com/ajax/libs/jquery/1.7/jquery.min.js"></script> 
<script src="<?php get_template_dir(); ?>/js/fixie.min.js"></script> 
<script src="<?php get_template_dir(); ?>/js/bundle.js"></script> 
</body>
</html>