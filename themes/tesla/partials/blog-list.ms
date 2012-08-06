<h1>Blog Posts</h1>

{{#looper}}
	{{#item}}
	
		<h2><a href="{{{link}}}">{{title}}</a></h2>
		<span>{{date}}</span>  
		<p>{{{teaser}}}</p>
		{{#lower}}Bob{{/lower}}
		
	{{/item}}
{{/looper}}