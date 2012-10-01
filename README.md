charlie
==================

A simple, no DB cms using [mustache][1] & [markdown][2].

## To Do (Bugs, Issues)
* Template is inherited on 404 errors for post pages (which results in tweet footer.
* Isolate Charlie into one directory. [charlie][public] (.htaccess). That way git can be used to easily update charlie. Public folder will contain [themes] & [content]. charlie will have a default themes and content folder within it, for when the site is first setup. Will need add a few IF statements to check for public stuff. 
* Needs a license.

## Roadmap (Features, Dreams, Wishes)
* Add draft ability. Files with draft_ prepended are ignored and not accessible.
* Fully functional info handler
* Add hooks to inject at certain points. (info handler ?)
* Page Caching
* Dropbox integration w/ content folder.
* More OOP and Class usage, omit orphaned functions or group into master toolbox class.
* Add .js pagination to core.
* Add optional feed formats (rss, xml,…)
* Create default theme with informational default content.


## Done
* [X] Proper 404 handling (pass back to index.php via .htaccess)
* [X] Add template_part() function (already there, doh!)
* [X] Page Content Object (with variable parsing?)
* [X] Add template language - mustache
* [X] Agnostic Loop function (diet WP loop)
* [X] Image Handling
* [X] Change Post Array sorting to something other than alphabetical by filename.
* [X] Sterilize everything from core and move into stephencreates.com or some such.
* [X] Make Feed Looper themeable with mustache parts (load feed object)
* [X] Add Post Dates as parts of file titles? (other ideas?) (used frontmatter as solution)
* [X] Update Feed Loop to match regular Content Looper. (merged into single looper)






[1]: http://mustache.github.com/  "Logic-less templates"
[2]: http://daringfireball.net/projects/markdown/ "Markdown"