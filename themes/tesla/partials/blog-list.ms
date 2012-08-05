<h1>Blog Posts</h1>
	
	
	{{#blog_looper}}
		{{#item}}
		
			<h2><a href="{{{link}}}" >{{title}}</a></h2>
			<span>{{date}}</span>  
			<p>{{{teaser}}}</p>
			
		{{/item}}
	{{/blog_looper}}