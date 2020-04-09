{
  "version": "https://jsonfeed.org/version/1",
  "user_comment": "This feed allows you to read the posts from this site in any feed reader that supports the JSON Feed format. To add this feed to your reader, copy the following URL — http://{{site_domain}}/{{post.type}}/feed/json — and add it your reader.",
  "title": "{{site_author}}'s {{post.type}} Feed",
  "description": "{{site_description}}",
  "home_page_url": "http://{{site_domain}}",
  "feed_url": "http://{{site_domain}}/{{post.type}}/feed/json",
  "site_author": {
    "name": "{{site_author}}",
    "url": "{{site_domain}}"
  },
  "items": [
  {{#post.feed}}
	{{#item}}
    {
      "title": "{{title}}",
      "date_published": "{{date}}",
      "id": "http://{{site_domain}}{{link}}",
      "url": "http://{{site_domain}}{{link}}",
      "content_html": "{{#f_markdown}}{{content}}{{/f_markdown}}",
      "summary": "{{summary}}"
    }
	{{/item}}
  {{/post.feed}}
  ]
}
