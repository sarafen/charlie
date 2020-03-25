
# ROADMAP
last updated: 03.23.20

## todo

- there are odd special characters in the json feed and rss feed files that will need correcting
- create a default folio template, visual work centered.
- enable check for maintenance_mode & create a custom template for it, first check in chain.
- static site generation capability: build a tree of all possible VIEWS, then create a build script to allow for a static build output so that charlie could be hosted on netlify, gh pages, etc.

## resolved
- `/content/_blocks` & `/content/imgs` are considered valid content that tries to load. Potentially exlude these from the Content Tree.
