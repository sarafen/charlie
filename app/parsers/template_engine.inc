<?php

// Template ENGINE


////////////////////////////////////////////////////

// Include CLASSES

////////////////////////////////////////////////////

require_once('./app/classes/class.page.inc');

////////////////////////////////////////////////////

// Create PAGE Object

////////////////////////////////////////////////////

//Create page object
$page = new Page();

////////////////////////////////////////////////////

// Construct the robust CONTENT loop.
// But really we're doing a lot of test stuff with 
// this.

////////////////////////////////////////////////////


if (INFO_HANDLER_TOGGLE == TRUE) {

	//Test output the path
	echo 'PATH: ',$page->the_path(),',';
	//echo '<br />';
	
	//Test output template
	echo 'TEMPLATE: ',$page->the_type(),',';
	//echo '<br />';
	
	//Test output title
	echo 'TITLE: ',$page->the_title(),',';
	//echo '<br />';
	
	//Test output parent
	echo 'PARENT: ',$page->get_parent();
	//echo '<br />';
	
	echo '<hr />';
}


////////////////////////////////////////////////////

// Construct the ERROR handler.

////////////////////////////////////////////////////

function error_handler($type,$description){
	
	echo 'Error '.$type.' '.$description;
};


////////////////////////////////////////////////////

// Construct the robust PARTIAL region(s).

////////////////////////////////////////////////////

function get_partial($name) {

	global $config;

	// This would be used like a diet version of Drupal's block system
	$file = './themes/'.THEME.'/partials/'.$name.'.tpl.php';
		
	include $file; 

};


////////////////////////////////////////////////////

// Construct the HEADER area.

////////////////////////////////////////////////////

function get_header(){	

	if (file_exists(HEADER)) {
		
		info_handler(INFO_HANDLER_TOGGLE); //Display Config INFO
	
		include HEADER;
		
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
	
		 $template = './themes/'.THEME.'/index.tpl.php';		 
	}
					
	//Check for PAGE Content Type - Load 'page.tpl.php' default
	
	//Establish 'page-[pagename].tpl.php' Template File Name Scheme
	
	
	//Check for PAGE Content Type - Load 'page[type].tpl.php' specific
	if 	($page->get_type() == 'page' && file_exists('./themes/'.THEME.'/page-'.$page->get_path().'.tpl.php')) {
		
		$template = './themes/'.THEME.'/page-'.$page->get_path().'.tpl.php';
	}
	
	//Fallback to default PAGE template - Load 'page.tpl.php' generic
	if ($page->get_type() == 'page' && !file_exists('./themes/'.THEME.'/page-'.$page->get_path().'.tpl.php')) {
	
		$template ='./themes/'.THEME.'/page.tpl.php';	
	} 
	
	//Check for POST Content Type - Load 'post-[type].tpl.php' specific
	if 	($page->get_type() == 'post' && file_exists('./themes/'.THEME.'/post-'.$page->get_parent().'.tpl.php')) {
		
		$template = './themes/'.THEME.'/post-'.$page->get_parent().'.tpl.php';
	}
	
	//Check for FEED Content Type - Load 'feed.tpl.php'
	if ($page->get_type() == 'feed' && empty($path)) {
	
		 $template = './themes/'.THEME.'/feed.tpl.php';		 
	} 
		
	//Include the Appropriate Template		
	if (MAINTENANCE_TOGGLE == TRUE) {include './themes/'.THEME.'/maintenance.tpl.php';} 
	elseif (file_exists($template)) {include $template;} else {include './themes/'.THEME.'/page.tpl.php';}
			
};


////////////////////////////////////////////////////

// Construct the FOOTER area.

////////////////////////////////////////////////////

function get_footer(){	

	if (file_exists(FOOTER)) {
	
		include FOOTER;
		
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

// Construct the INFO handler. // Needs a good reworking

////////////////////////////////////////////////////

function info_handler($switch = FALSE){

/*
	if ($switch == TRUE) {

		$GLOBALS["switch"] = $switch;
		
		echo 'CONFIG INFO <br />';
		echo 'Theme: '.$GLOBALS["theme"].'<br />';
		echo 'Theme Directory: '.$GLOBALS["theme_dir"].'<br />';
		echo '<hr />';
	
	} else {$switch = "";}
*/
};

