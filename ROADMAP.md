
# ROADMAP
last updated: 03.25.20

## todo
- create a default folio template, visual work centered.
- consider removing date formatting from looper config, and instead let it be done with a lambda.
- need to add a sort_by_direction (ASC, DES), to looper config
- look into markdown extra capabilities to do classes more easily
- enable check for maintenance_mode & create a custom template for it, first check in chain.
- static site generation capability: build a tree of all possible VIEWS, then create a build script to allow for a static build output so that charlie could be hosted on netlify, gh pages, etc.
- update LICENSE

## resolved
- `/content/_blocks` & `/content/imgs` are considered valid content that tries to load. Potentially exlude these from the Content Tree.
- there are odd special characters in the json feed and rss feed files that will need correcting
