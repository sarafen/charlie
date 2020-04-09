{{#looper.blog}}
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
</ul>
{{^item}}

		<article>
			<h3>no blog posts found</h3>
			<p>( Nothing, Nada, Zip &hellip; )</p>
		</article>

{{/item}}

{{/looper.blog}}
