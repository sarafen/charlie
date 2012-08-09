<h1>Blog Posts</h1>

{{#blog_looper}}	
<div class="paginate">
{{#item}}
	<article>
	<h2><a href="{{{link}}}">{{title}}</a></h2>
	<span>{{date}}</span>  
	<p>{{{teaser}}}</p>
	</article>
{{/item}}
</div>
{{/blog_looper}}