{{>header}}

<body>

{{{content}}}

<hr />
<br />

<h2>Blog List</h2>

<p>This is an example loop displaying the default dummy Blog posts.</p>

{{>blog-list}}

<a class="rss" href="/blog/feed">&rarr; rss</a>

<hr />
<br />

<p>This loop's settings can be found in the root 'config.ini' file. It is rendered with a mustache tag in the 'index.ms' template file.</p>

<p>Individual blog posts can be found in the '/content/blog/' directory.</p>


{{>footer}}

</body>
</html>