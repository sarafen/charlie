
{{>header}}

<body>

{{{content}}}

<p>This is an example loop displaying the default dummy Work posts.</p>

{{#looper.work}}
<ul>
{{#item}}

<li>
<article>
	<h2><a href="{{{link}}}">{{title}}</a></h2>
	<time class="article-date">{{date}}</time>

	<p>{{summary}}</p>

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

{{/looper.work}}

<a href="/work/pg/1">Archive</a>

{{>footer}}
