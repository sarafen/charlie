
{{>header}}

<body>

{{#f_markdown}}
# {{#f_capitalize}}{{post.type}}{{/f_capitalize}} Archive
{{/f_markdown}}

<p>This is the archive displaying the default dummy {{post.type}} posts.</p>

{{#post.archive}}

{{#item}}

<article>
	<h2><a href="{{{link}}}">{{title}}</a></h2>
	<time class="article-date">{{date}}</time>

	<p>{{summary}}</p>

</article>

{{/item}}

{{^item}}
	<li>
		<article>
			<h3>Nothing, Nada, Zip &hellip;</h3>
		</article>
	</li>
{{/item}}

{{#post.pagination}}
<nav>
<ul>
{{#item}}
    <li>{{#link}}<a href="{{link}}">{{/link}}{{num}}{{#link}}</a>{{/link}}</li>
{{/item}}

</ul>
</nav>
{{/post.pagination}}

{{/post.archive}}


{{>footer}}
