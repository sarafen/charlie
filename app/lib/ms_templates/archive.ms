
{{>header}}

<body>

<h1>{{post.type}} Archive</h1>

{{#post.archive}}

{{#item}}

<article>
	<h2><a href="{{{link}}}">{{title}}</a></h2>
	<time class="article-date">{{date}}</time>

	<p>{{summary}}</p>

</article>

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
