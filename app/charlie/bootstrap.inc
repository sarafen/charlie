<?php

function bootstrap_full() {

////////////////////////////////////////////////////

// Include PARSERS

////////////////////////////////////////////////////

require_once './app/charlie/parsers/mustache/Autoloader.php';
Mustache_Autoloader::register();

require_once './app/charlie/parsers/markdown.inc';

require_once './app/charlie/parsers/frontmatter.inc';

require_once './app/charlie/parsers/ini.inc';

////////////////////////////////////////////////////

// Include RANDOM (for now)

////////////////////////////////////////////////////

//require_once './app/charlie/parsers/loop_engine.inc';

////////////////////////////////////////////////////

// Include CORE Classes

////////////////////////////////////////////////////

require_once './app/charlie/classes/class.Settings.inc';

require_once './app/charlie/classes/class.Helpers.inc';

require_once './app/charlie/classes/class.Route.inc';

require_once './app/charlie/classes/class.Page_Data.inc';

require_once './app/custom/classes/class.custom.Page_Data.inc';

require_once './app/charlie/classes/class.Template.inc';

require_once './app/charlie/classes/class.Loop.inc';

require_once './app/charlie/classes/class.View.inc';

////////////////////////////////////////////////////

// Include ENGINE

////////////////////////////////////////////////////

require_once './app/charlie/engine.inc';



};