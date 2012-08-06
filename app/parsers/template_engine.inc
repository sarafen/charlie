<?php

// Template ENGINE


////////////////////////////////////////////////////

// Include CLASSES

////////////////////////////////////////////////////

require_once('./app/classes/class.Data.inc');
require_once('./app/classes/custom/class.custom.Data.inc');

////////////////////////////////////////////////////

// Create PAGE Object

////////////////////////////////////////////////////

$page = new Data();

////////////////////////////////////////////////////

// Create VIEW DATA Object

////////////////////////////////////////////////////

//$data = new viewData();

////////////////////////////////////////////////////

// Create MUSTACHE_ENGINE VIEW Object

////////////////////////////////////////////////////

if (Config::get_template_engine() == 'mustache') {

	$view = new Mustache_Engine(array(
	    'template_class_prefix' => '__MyTemplates_',
	    'cache' => dirname(__FILE__).'/tmp/cache/mustache',
	    'loader' => new Mustache_Loader_FilesystemLoader(dirname(dirname(dirname(__FILE__))).'/themes/'.THEME),
	    'partials_loader' => new Mustache_Loader_FilesystemLoader(dirname(dirname(dirname(__FILE__))).'/themes/'.THEME.'/partials'),
	    'escape' => function($value) {
	        return htmlspecialchars($value, ENT_COMPAT, 'UTF-8');
	    },
	));

}


////////////////////////////////////////////////////

// Create TWIG_ENGINE VIEW Object

////////////////////////////////////////////////////

/*
if (Config::get_template_engine() == 'twig') {

	$loader = new Twig_Loader_Filesystem(dirname(dirname(dirname(__FILE__))).'/themes/'.THEME);
	
	$view = new Twig_Environment($loader, array(
	    'cache' => dirname(dirname(dirname(__FILE__))).'/cache/templates',
	    'debug' => true,
	));

}
*/

//$view->removeExtension('escaper');

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

// Construct the BODY area.

////////////////////////////////////////////////////

function render_template($page,$view,$data) {	

	$template = "";
	$ext = '.ms';
	
	//Check for FRONT Page - Load 'index.tpl.php'
	if ($page->get_type() == 'index') {
	
		 //$template = './themes/'.THEME.'/index.tpl.php';
		 //$template = 'index.tpl.php';
		 
		 $template = 'index';
		 //$partials;

	}
					
	//Check for PAGE Content Type - Load 'page.tpl.php' default
	
	//Establish 'page-[pagename].tpl.php' Template File Name Scheme
	
	
	//Check for PAGE Content Type - Load 'page[type].tpl.php' specific
	if 	($page->get_type() == 'page' && file_exists('./themes/'.THEME.'/page-'.$page->get_path().$ext)) {
		
		//$template = './themes/'.THEME.'/page-'.$page->get_path().'.tpl.php';
		$template = 'page-'.$page->get_path();
		
	}
	
	//Fallback to default PAGE template - Load 'page.tpl.php' generic
	if ($page->get_type() == 'page' && !file_exists('./themes/'.THEME.'/page-'.$page->get_path().$ext)) {
	
		//$template ='./themes/'.THEME.'/page.tpl.php';	
		$template = 'page';
	} 
	
	//Check for POST Content Type - Load 'post-[type].tpl.php' specific
	if 	($page->get_type() == 'post' && file_exists('./themes/'.THEME.'/post-'.$page->get_parent().$ext)) {
		
		//$template = './themes/'.THEME.'/post-'.$page->get_parent().'.tpl.php';
		$template = 'post-'.$page->get_parent();
	}
	
	//Check for FEED Content Type - Load 'feed.tpl.php'
	if ($page->get_type() == 'feed' && empty($path)) {
	
		 //$template = './themes/'.THEME.'/feed.tpl.php';
		 //include $template;
		 
		 $template = 'feed';	 
	} 
		
	//Include the Appropriate Template		
	//if (MAINTENANCE_TOGGLE == TRUE) {include './themes/'.THEME.'/maintenance.tpl.php';}
	
	if (MAINTENANCE_TOGGLE == TRUE) {$template = 'maintenance';echo $view->render($template,$page);}  
	
	elseif (file_exists('./themes/'.THEME.'/'.$template.'.ms')) { //make extension configurable
	
		$template_engine = Config::get_template_engine();
	
		// Add a config.info toggle for which templating engine to use.
		
		if ($template_engine == 'mustache') {echo $view->render($template,$page);} //mustache implementation
		
/* 		else if ($template_engine == 'twig') {$view->display($template, array('data' => $data));} //twig implimentation */
		
		
		else {include ($template);} //default implementation
	
			
	} else {
	
		//include './themes/'.THEME.'/page.tpl.php';	
		echo $view->render('page',$data);	
	}			
};


////////////////////////////////////////////////////

// Combine Page Regions & Render FULL PAGE

////////////////////////////////////////////////////

		
render_template($page,$view,$page);


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

