{{#blog_looper}}	
<ul class="article-list">
{{#item}}
	<li>
		<article>
			<h3><a href="{{{link}}}">{{title}}</a></h3>
			<time class="article-date">{{date}}</time>
			
			<p>{{teaser}}</p>
			
		</article>
	</li>
{{/item}}

{{^item}}
	<li>
		<article>
			<h3>Nothing, Nada, Zip &hellip;</h3>
		</article>
	</li>
{{/item}}
</ul>
{{/blog_looper}}
