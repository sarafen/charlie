{{feed_header}}

{{>atom-feed-header}}

{{#feed_looper}}
		{{#item}}
		
			{{{entry}}}
			
		{{/item}}
{{/feed_looper}}




{{! Add more stuff to edit here in the future. }}
{{! For now you can just specific what content to put in the feed. }}

{{>atom-feed-footer}}