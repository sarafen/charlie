<?php

/**
  * Bootstrap
  *
  * Starts things up.
  * 
  * Needs an Autoloader at some point.
  */

function bootstrap_full() {

////////////////////////////////////////////////////
//
// Include PARSERS
//
////////////////////////////////////////////////////

require_once './app/parsers/Mustache/Autoloader.php';
Mustache_Autoloader::register();

require_once './app/parsers/markdown.inc';

require_once './app/parsers/frontmatter.inc';

require_once './app/parsers/ini.inc';

////////////////////////////////////////////////////
//
// Include RANDOM (for now)
//
////////////////////////////////////////////////////

//require_once './app/parsers/loop_engine.inc';

////////////////////////////////////////////////////
//
// Include CORE Classes
//
////////////////////////////////////////////////////

require_once './app/classes/class.Settings.inc';
Charlie_Settings::init();

require_once './app/classes/class.Helpers.inc';

require_once './app/classes/class.Route.inc';

require_once './app/classes/class.Page_Data.inc';

require_once './extensions/classes/class.custom.Page_Data.inc';

require_once './app/classes/class.Template.inc';

require_once './app/classes/class.Loop.inc';

require_once './app/classes/class.View.inc';

////////////////////////////////////////////////////
//
// Include ENGINE
//
////////////////////////////////////////////////////

require_once './app/engine.inc';



};