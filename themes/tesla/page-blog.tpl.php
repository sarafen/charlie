<?php get_header(); ?>

<body id="blog">


<h1><a href="/" id="logo">Stephen Creates</a></h1>

<?php get_block('menu'); ?>
 
<section id="main-content">
	
	<?php get_content(); ?>
	
	
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