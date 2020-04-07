
# ROADMAP
last updated: 04.06.20

## todo
- Generally the code could do with some overall refactor, cleanup, inline documentation, etc. It works, but is it "pretty"? Probably not. If you'd like to help make it "pretty", feel free to fork the repo and initiate a PR in accordance with the [Contribution guidelines](https://github.com/StephenLovell/charlie/#contributing)
- create a default folio template, visual work centered.
- create a default comics template, strips/dailes/chapter-based focused.
- consider removing date formatting from looper config, and instead let it be done with a lambda. Alternatively you can write out your own custom formatting as a frontmatter field too. Might be worth mentioning in the docs as a fallback route.
- look into markdown extra capabilities to do classes more easily
- enable check for maintenance_mode & create a custom template for it, first check in chain.
- static site generation capability: build a tree of all possible VIEWS, then create a build script to allow for a static build output so that charlie could be hosted on netlify, gh pages, etc.
- add customizable redirects in the config.json. Someone might want the blog archive and the /blog page to be one and the same. In this instance you might want to collapse them into one so that you had /blog/pg/1, but if you tried to go to /blog you'd get redirected to /blog/pg/1.
- refactor sort_by and sort_order logic for regular loopers, archives loopers, and feeds loopers, lotta repeating sections
- most of the code could do with better comment documentation
- look into making pagination more flexible (example use-case a daily strip comic)

## resolved
- `/content/_blocks` & `/content/imgs` are considered valid content that tries to load. Potentially exclude these from the Content Tree.
- there are odd special characters in the json feed and rss feed files that will need correcting
- .dotfiles and dirs inside of content type folders are properly ignored now. This means that someone can make a /drafts folder to work inside of.
- need to add a sort_by_direction (ASC, DES), to looper config
- need to add sort_by_direction (ASC, DESC), to archive config (possibly feed, but not seeing a proper usecase there?)
- update LICENSE
