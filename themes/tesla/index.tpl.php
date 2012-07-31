<?php get_header(); ?>


<body id="front">


<h1><a href="/" id="logo">Stephen Creates</a></h1>

<?php get_partial('menu'); ?>

<?php get_content(); ?>

<section id="news">
	
</section>

<section id="recent-work">
	<a href="#" class="img one">dezby &rarr;</a>
	<a href="#" class="img two">ambalamb &rarr;</a>
	<a href="#" class="img three">Adulting Blog &rarr;</a>
</section>

<footer role="contentinfo">
<p>Created by Stephen Lovell</p>

<!-- <p>&copy; 2012</p> -->

</footer>

<?php news(); ?>

<script src="http://ajax.googleapis.com/ajax/libs/jquery/1.7/jquery.min.js"></script> 
<script src="<?php get_theme_dir(); ?>/js/fixie.min.js"></script> 
<script src="<?php get_theme_dir(); ?>/js/moment.min.js"></script> 
<script src="<?php get_theme_dir(); ?>/js/jq.tweet.min.js"></script> 
<script src="<?php get_theme_dir(); ?>/js/bundle.js"></script> 
</body>
</html>