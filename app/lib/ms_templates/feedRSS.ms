<?xml version="1.0" encoding="utf-8"?>
<feed xmlns="http://www.w3.org/2005/Atom">

<title>{{site_author}}'s {{post.type}} Feed</title>
<subtitle>{{site_description}}</subtitle>
<link href="http://{{site_domain}}/feed/" hreflang="en" rel="self" type="application/atom+xml"/>
<link href="http://{{site_domain}}/" hreflang="en" rel="alternate" type="text/html"/>

<updated>2012-07-15T10:50:43+10:00</updated>
<generator uri="http://charliecms.com/" version="1.0">Charlie</generator>

<author>
<name>{{site_author}}</name>
<uri>http://{{site_domain}}</uri>
</author>

<id>tag:{{site_domain}},2012:/feed/</id>
<rights> {{current_year}} {{site_author}}</rights>

{{#post.feed}}
		{{#item}}

		<entry>
			<title>{{title}}</title>
			<id>http://{{site_domain}}{{link}}</id>
			<updated>{{date}}</updated>
			<link rel="alternate" type="text/html" href="http://{{site_domain}}{{link}}" />
			<content type="xhtml" xml:lang="en">
				<div xmlns="http://www.w3.org/1999/xhtml">

					<summary>{{summary}}</summary>

				</div>
		   </content>
		</entry>

		{{/item}}
{{/post.feed}}

</feed>
