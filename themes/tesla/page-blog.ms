{{>header}}

<body id="blog">


<h1><a href="/" id="logo">Stephen Creates</a></h1>

{{>menu}}
 
<section id="main-content">

	{{>blog-list}}	
	
	{{#dynamic_looper}}bob{{/dynamic_looper}}
	
</section>

<a href="/feed">Feed</a>







{{>footer}}

<script src="http://ajax.googleapis.com/ajax/libs/jquery/1.7/jquery.min.js"></script> 
<script src="{{theme_dir}}/js/fixie.min.js"></script> 
<script src="{{theme_dir}}/js/bundle.js"></script> 
</body>
</html>