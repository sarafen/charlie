<?php


////////////////////////////////////////////////////

// Include CLASSES

////////////////////////////////////////////////////

include_once "./app/classes.inc";

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

// Construct the basic CONTENT region.

////////////////////////////////////////////////////

// This section needs expansion to accomodate broader
// customization. AND allow more flexible MD conversion.

function get_content() {	

	//Grab the URL

	$uri = $_SERVER['REQUEST_URI'];
	$path_part = explode('/', $uri);
	//$path = end($tmp);
	
	$file = "";
	 
		//Check for FRONT Page
		
		if ($path_part[1] == null || !isset($path_part[1])) {
		
			$file = './content/pages/front.md';		 
		}
				
		//Check for ARTICLE Content Type - leading slug
	
		if ($path_part[1] == 'articles' && $path_part[2] != null && empty($path_part[3])) {
		
			 $file = './content/articles/'.$path_part[2].'.md';		 
		}  
		
		//Check for BLOG Content Type - leading slug
	
		if ($path_part[1] == 'blog' && $path_part[2] != null && empty($path_part[3])) {
		
			 $file = './content/blog/'.$path_part[2].'.md';		 
		} 	 
		
		//Check for PAGE Content Type - No leading slug
		
		if (empty($path_part[2]) && $path_part[1] != null && empty($path_part[3])) {
		
			$file ='./content/pages/'.$path_part[1].'.md';			
		}
			
		//Include the Appropriate Content		
		
		if (file_exists($file) && $file != null) {md($file);} else {include './themes/default/404.tpl.php';}	
};

////////////////////////////////////////////////////

// Construct the robust CONTENT loop.

////////////////////////////////////////////////////




// This would be used like a diet version of the WP loop system. 




////////////////////////////////////////////////////

// Construct the robust BLOCK region(s).

////////////////////////////////////////////////////

function get_block($name){

// This would be used like a diet version of Drupal's block system

	$file = './content/blocks/'.$name.'.blk';
	
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

function render_page() {	

	//Grab the URL
	
	$uri = $_SERVER['REQUEST_URI'];
	$path_part = explode('/', $uri);
	//$path = end($tmp);
	
	$template = "";
	
	
	//Check for FRONT Page - Load 'index.tpl.php'
	
	if ($path_part[1] == null) {
	
		 $template = './themes/'.$GLOBALS['theme'].'/index.tpl.php';		 
	}
			
	
	//Check for ARTICLE Content Type - Load 'article.tpl.php'
	
	if ($path_part[1] == 'articles' && $path_part[2] != null) {
	
		 $template = './themes/'.$GLOBALS['theme'].'/article.tpl.php';		 
	}  	 
	
	
	//Check for PAGE Content Type - Load 'page.tpl.php' default
	
	//Establish 'page-[pagename].tpl.php' Template File Name Scheme
	
	//$file = 'templates/'.$GLOBALS['template'].'/page-'.$path_part[1].'.tpl.php';
	
	if (empty($path_part[2]) && $path_part[1] != null && !file_exists('./themes/'.$GLOBALS['theme'].'/page-'.$path_part[1].'.tpl.php')) {
	
		$template ='./themes/'.$GLOBALS['theme'].'/page.tpl.php';	
	} 
	
	//Check for PAGE Content Type - Load 'page.tpl.php' specific
	
	if 	(empty($path_part[2]) && $path_part[1] != null && file_exists('./themes/'.$GLOBALS['theme'].'/page-'.$path_part[1].'.tpl.php')) {
		
		$template = './themes/'.$GLOBALS['theme'].'/page-'.$path_part[1].'.tpl.php';
	}
	
	//Check for POST Content Type - Load 'page.tpl.php' specific
	
	if 	(isset($path_part[2]) && $path_part[1] != null && file_exists('./themes/'.$GLOBALS['theme'].'/post-'.$path_part[1].'.tpl.php')) {
		
		$template = './themes/'.$GLOBALS['theme'].'/post-'.$path_part[1].'.tpl.php';
	}
			
	//Include the Appropriate Template		
	
	if ($GLOBALS['setting_maintenance'] == TRUE) {include './themes/'.$GLOBALS['theme'].'/maintenance.tpl.php';} 
	elseif (file_exists($template)) {include $template;} else {include './themes/'.$GLOBALS['theme'].'/index.tpl.php';}

	// INFO Reporting
	
	//if ( $GLOBALS['switch'] == TRUE) {
	

	
	//}				
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

		
render_page();


////////////////////////////////////////////////////

// Parse MARKDOWN content

////////////////////////////////////////////////////


function md($file) {

include_once "markdown.inc";
$raw_content = file_get_contents($file); $content = Markdown($raw_content);

echo $content;

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