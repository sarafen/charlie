{{>header}}

<body id="blog">


<h1><a href="/" id="logo">Stephen Creates</a></h1>

{{>menu}}
 
<section id="main-content">

	<h1>Blog Posts</h1>
	
	
	{{#blog_looper}}
		{{#items}}
			{{{item}}}
		{{/items}}
	{{/blog_looper}}
	
	
</section>







<footer role="contentinfo">
<p>Created by Stephen Lovell</p>

<!-- <p>&copy; 2012</p> -->

</footer>


<script src="http://ajax.googleapis.com/ajax/libs/jquery/1.7/jquery.min.js"></script> 
<script src="{{theme_dir}}/js/fixie.min.js"></script> 
<script src="{{theme_dir}}/js/bundle.js"></script> 
</body>
</html>