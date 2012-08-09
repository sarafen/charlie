charlie
==================

A simple, no DB cms using [mustache][1] & [markdown][2].

## To Do
* Add draft ability. Files with draft_ prepended are ignored and not accessible.
* Fully functional info handler
* Add hooks to inject at certain points. (info handler ?)
* Page Caching
* Dropbox integration w/ content folder.
* More OOP and Class usage, omit orphaned functions or group into master toolbox class.
* Add .js pagination to core.
* Add optional feed formats (rss,xml,…)
* Sterilize everything from core and move into stephencreates.com or some such.

## Done
* [X] Proper 404 handling (pass back to index.php via .htaccess)
* [X] Add template_part() function (already there, doh!)
* [X] Page Content Object (with variable parsing?)
* [X] Add template language - mustache
* [X] Agnostic Loop function (diet WP loop)
* [X] Image Handling




[1]: http://mustache.github.com/  "Logic-less templates"
[2]: http://daringfireball.net/projects/markdown/ "Markdown"