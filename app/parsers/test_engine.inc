<?php

////////////////////////////////////////////////////

// Construct the robust CONTENT loop.
// But really we're doing a lot of test stuff with this.

////////////////////////////////////////////////////

require_once('./app/classes/class.page.inc');


 
//Create page object
$page = new Page();


//Test output the path
$page->the_path();


//Test output template
$page->the_type();

//Test output title
$page->the_title();

//Test output parent
echo 'Parent:'.$page->get_parent();




////////////////////////////////////////////////////

// Include CLASSES

////////////////////////////////////////////////////

require_once "./app/classes/class.settings.inc";
require_once('./app/classes/class.page.inc');

////////////////////////////////////////////////////

// Parse & Pass In INI SETTINGS

////////////////////////////////////////////////////
 
$settings = Settings::getInstance('./app/config.info');

	//General Info
	$setting_maintenance = strip_tags($settings->General_Info['maintenance_mode']); // ! This and others throw ERROR because of direct property access.!
	
	if ($setting_maintenance == 'ON,1') {
	
		$setting_maintenance = TRUE;
	}
	
	$setting_info_handler = strip_tags($settings->General_Info['info_handler']);
	
	if ($setting_info_handler == 'ON,1') {
	
		$setting_info_handler = TRUE;
	}
	
	//Theme Settings
	$theme = strip_tags($settings->Theme_Settings['theme']); 


////////////////////////////////////////////////////

// Set THEME directory

////////////////////////////////////////////////////

$theme_dir = 'themes/'.$theme;

function get_template_dir() {

	$site_url = $_SERVER['SERVER_NAME'];

	echo 'http://'.$site_url.'/'.$GLOBALS["theme_dir"];

};

////////////////////////////////////////////////////

// Set Default Template.

////////////////////////////////////////////////////

if (!file_exists($theme_dir) && !is_dir($theme_dir)) {

	$theme = "default";
	
}

////////////////////////////////////////////////////

// Establish the primitive TEMPLATE Assembly.

////////////////////////////////////////////////////

$header = 'themes/'.$theme.'/header.tpl.php';
$footer = 'themes/'.$theme.'/footer.tpl.php';

////////////////////////////////////////////////////

// GLOBALS

////////////////////////////////////////////////////

$GLOBALS["theme"]=$theme;
$GLOBALS["theme_dir"]=$theme_dir;
$GLOBALS["header"]=$header;
$GLOBALS["footer"]=$footer;	
$GLOBALS["setting_info_handler"]=$setting_info_handler;
$GLOBALS["setting_maintenance"]=$setting_maintenance;

////////////////////////////////////////////////////

// Construct the ERROR handler.

////////////////////////////////////////////////////

function error_handler($type,$description){
	
	echo 'Error '.$type.' '.$description;
};


////////////////////////////////////////////////////

// Construct the robust PARTIAL region(s).

////////////////////////////////////////////////////

function get_partial($name){

	// This would be used like a diet version of Drupal's block system
	$file = './themes/'.$GLOBALS['theme'].'/partials/'.$name.'.tpl.php';
		
	include $file; 

};

////////////////////////////////////////////////////

// Construct the HEADER area.

////////////////////////////////////////////////////

function get_header(){	

	if (file_exists($GLOBALS['header'])) {
		
		info_handler($GLOBALS['setting_info_handler']); //Display Config INFO
	
		include $GLOBALS['header'];
		
	} else {
	
		error_handler("404","Template File Not Found");
	}
};

////////////////////////////////////////////////////

// Construct the BODY area.

////////////////////////////////////////////////////

function render_template($page,$settings) {	


	//Grab the URL
	//$uri = $_SERVER['REQUEST_URI'];
	//$path_part = explode('/', $uri);
	//$path = end($path_part);
	
	$template = "";
	
	
	//Check for FRONT Page - Load 'index.tpl.php'
	if ($page->get_type() == 'index') {
	
		 $template = './themes/'.$GLOBALS['theme'].'/index.tpl.php';		 
	}
					
	//Check for PAGE Content Type - Load 'page.tpl.php' default
	
	//Establish 'page-[pagename].tpl.php' Template File Name Scheme
	
	
	//Check for PAGE Content Type - Load 'page[type].tpl.php' specific
	if 	($page->get_type() == 'page' && file_exists('./themes/'.$GLOBALS['theme'].'/page-'.$page->get_path().'.tpl.php')) {
		
		$template = './themes/'.$GLOBALS['theme'].'/page-'.$page->get_path().'.tpl.php';
	}
	
	//Fallback to default PAGE template - Load 'page.tpl.php' generic
	if ($page->get_type() == 'page' && !file_exists('./themes/'.$GLOBALS['theme'].'/page-'.$page->get_path().'.tpl.php')) {
	
		$template ='./themes/'.$GLOBALS['theme'].'/page.tpl.php';	
	} 
	
	//Check for POST Content Type - Load 'post-[type].tpl.php' specific
	if 	($page->get_type() == 'post' && file_exists('./themes/'.$GLOBALS['theme'].'/post-'.$page->get_parent().'.tpl.php')) {
		
		$template = './themes/'.$GLOBALS['theme'].'/post-'.$page->get_parent().'.tpl.php';
	}
	
	//Check for FEED Content Type - Load 'feed.tpl.php'
	if ($page->get_type() == 'feed' && empty($path)) {
	
		 $template = './themes/'.$GLOBALS['theme'].'/feed.tpl.php';		 
	} 
		
	//Include the Appropriate Template		
	if ($GLOBALS['setting_maintenance'] == TRUE) {include './themes/'.$GLOBALS['theme'].'/maintenance.tpl.php';} 
	elseif (file_exists($template)) {include $template;} else {include './themes/'.$GLOBALS['theme'].'/page.tpl.php';}
			
};


////////////////////////////////////////////////////

// Construct the FOOTER area.

////////////////////////////////////////////////////

function get_footer(){	

	if (file_exists($GLOBALS['footer'])) {
	
		include $GLOBALS['footer'];
		
	} else {
	
		error_handler("404","Template File Not Found");
	}
};

////////////////////////////////////////////////////

// Combine Page Regions & Render FULL PAGE

////////////////////////////////////////////////////

		
render_template($page,$settings);


////////////////////////////////////////////////////

// Parse MARKDOWN content

////////////////////////////////////////////////////

function md($file) {

	include_once "markdown.inc";
	$raw_content = file_get_contents($file); $content = Markdown($raw_content);
	
	echo $content;

}

function return_md($file) {

	include_once "markdown.inc";
	$raw_content = file_get_contents($file); $content = Markdown($raw_content);
	
	return $content;

}

////////////////////////////////////////////////////

// Parse FEED content

////////////////////////////////////////////////////

function feed($file) {

	$raw_content = file_get_contents($file);
	
	header('Content-type: text/xml');
	
	echo $raw_content;

}

////////////////////////////////////////////////////

// Construct the INFO handler.

////////////////////////////////////////////////////

function info_handler($switch = FALSE){

	if ($switch == TRUE) {

		$GLOBALS["switch"] = $switch;
		
		echo 'CONFIG INFO <br />';
		echo 'Theme: '.$GLOBALS["theme"].'<br />';
		echo 'Theme Directory: '.$GLOBALS["theme_dir"].'<br />';
		echo '<hr />';
	
	} else {$switch = "";}
};

