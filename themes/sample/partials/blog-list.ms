{{#blog_looper}}	
<ul class="article-list">
{{#item}}
	<li>
		<article>
			<h2><a href="{{{link}}}">{{title}}</a></h2>
			<time class="article-date">{{date}}</time>
			
		</article>
	</li>
{{/item}}

{{^item}}
	<li>
		<article>
			<h2>Nothing, Nada, Zip &hellip;</h2>
		</article>
	</li>
{{/item}}
</ul>
{{/blog_looper}}
