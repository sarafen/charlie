{{>header}}

<body id="blog">


<h1><a href="/" id="logo">Stephen Creates</a></h1>

{{>menu}}
 
<section id="main-content">
	

{{>blog-list}}
	
	
</section>

<a href="/feed">Feed</a>







{{>footer}}

<script src="http://ajax.googleapis.com/ajax/libs/jquery/1.7.1/jquery.min.js"></script> 
<script src="{{theme_dir}}/js/jq.flexipage.min.js"></script> 
<script type="text/javascript">
$(document).ready(function(){

	$('.paginate').flexipage({
		perpage:10,
		parent: 'section',
		element: 'article',
		showcounter: true,
   });
});
</script>
</body>
</html>