
{{>header}}

<body>

{{{content}}}



<p>This is an example loop displaying the default dummy Blog posts.</p>

{{#looper.blog}}

{{#item}}

<article>
	<h2><a href="{{{link}}}">{{title}}</a></h2>
	<time class="article-date">{{date}}</time>

	<p>{{summary}}</p>

</article>

{{/item}}

{{^item}}

		<article>
		<h2>no blog posts found</h2>
			<p>( Nothing, Nada, Zip &hellip; )</p>
		</article>

{{/item}}

{{/looper.blog}}

<a href="/blog/pg/1">Archive</a> | <a href="/blog/feed/rss">RSS</a> | <a href="/blog/feed/json">JSON</a>

{{{block.blog_explainer}}}


{{>footer}}
