<?php

// Random Functions that need handling

function md($file) {

	$raw_content = file_get_contents($file); $content = Markdown($raw_content);
	
	echo $content;

}

function return_md($file) {

	$raw_content = file_get_contents($file); $content = Markdown($raw_content);
	
	return $content;

}

////////////////////////////////////////////////////

// Create SETTINGS Object

////////////////////////////////////////////////////

//$settings = Charlie_Settings::('./app/config.info');


////////////////////////////////////////////////////

// Define CONSTANTS

////////////////////////////////////////////////////

define('DOMAIN', 'http://'.$_SERVER['SERVER_NAME']);
//define('THEME', Charlie_Settings::get_theme());
define('THEME', 'default');
define('THEME_DIR', Charlie_Settings::get_theme_dir());
define('MAINTENANCE_TOGGLE',  Charlie_Settings::get_maintenance_toggle());

////////////////////////////////////////////////////

// Create PAGE ROUTE Object

////////////////////////////////////////////////////

$page_route = new Charlie_Route();

////////////////////////////////////////////////////

// Create PAGE DATA Object

////////////////////////////////////////////////////

$page_data = new Page_data($page_route);

//Load Misc. Default Values
$page_data->add_value('current_year',date("Y"));
$page_data->add_value('theme_dir','http://'.$_SERVER['SERVER_NAME'].'/themes/'.THEME);

//Load Default Loops
$page_data->add_looper(
	'feed_looper',
	array(
		'loop_type' => 'feed',
		'content_type' => 'blog',
		'date_format' => ''
	)
);

//Load Custom Loops
if (file_exists('./themes/'.THEME.'/loops.inc')) {

	require_once './themes/'.THEME.'/loops.inc';
	
}

////////////////////////////////////////////////////

// Create VIEW Object

////////////////////////////////////////////////////

$view = new Charlie_View();

////////////////////////////////////////////////////

// Create TEMPLATE Object

////////////////////////////////////////////////////

$template = new Charlie_Template($page_data);

////////////////////////////////////////////////////

// Render VIEW Object

////////////////////////////////////////////////////
		
//Include the Appropriate Template		
//if (MAINTENANCE_TOGGLE == TRUE) {include './themes/'.THEME.'/maintenance.ms';}

if (MAINTENANCE_TOGGLE == TRUE) {$template->set('maintenance'); echo $view->render($template->fetch(),$page_data);}  

elseif (file_exists('./themes/'.THEME.'/'.$template->fetch().'.ms')) { //make extension configurable
	
	// Add a config.info toggle for which templating engine to use.
	
	echo $view->render($template->fetch(),$page_data);
	
}

else {

	//include './themes/'.THEME.'/page.ms';	
	echo $view->render('page',$page_data);	
	
}	