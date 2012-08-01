charlie
==================

A simple, lightweight, no db cms with a templating system.

## To Do
* Add draft ability. Files with draft_ prepended are ignored and not accessible.
* Fully functional info handler
* Page Content Object (with variable parsing?)
* Image Handling
* Agnostic Loop function (diet WP loop)
* Add hooks to inject at certain points. (info handler ?)
* Add template language - mustache
* Page Caching
* Dropbox integration w/ content folder.
* More OOP and Class usage, omit orphaned functions or group into master toolbox class.

## Done
* [X] Proper 404 handling (pass back to index.php via .htaccess)
* [X] Add template_part() function (already there, doh!)