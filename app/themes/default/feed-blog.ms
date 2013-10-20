<?xml version="1.0" encoding="utf-8"?>
<feed xmlns="http://www.w3.org/2005/Atom">

<title>{{author}}'s Blog Feed</title>
<subtitle>{{site_description}}</subtitle>
<link href="http://{{domain}}/feed/" hreflang="en" rel="self" type="application/atom+xml"/>
<link href="http://{{domain}}/" hreflang="en" rel="alternate" type="text/html"/>

<updated>2012-07-15T10:50:43+10:00</updated>
<generator uri="http://charliecms.com/" version="1.0">Charlie</generator>

<author>
<name>{{author}}</name>
<uri>http://{{domain}}</uri>
</author>

<id>tag:{{domain}},2012:/feed/</id>
<rights> {{current_year}} {{author}}</rights>

{{#blog-feed_looper}}
		{{#item}}
		
		<entry>
			<title>{{title}}</title>
			<id>{{id}}</id>
			<updated>{{date}}</updated>
			<link rel="alternate" type="text/html" href="{{link}}" />
			<content type="xhtml" xml:lang="en">
				<div xmlns="http://www.w3.org/1999/xhtml">
				  	  
					<summary>{{teaser}}</summary>
				  
				</div>
		   </content>
		</entry>
			
		{{/item}}
{{/blog-feed_looper}}

</feed>