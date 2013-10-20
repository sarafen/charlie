<?php

/**
  * Startup
  *
  * Starts things up.
  * 
  */

function startup_full() {

	require_once $_SERVER['DOCUMENT_ROOT'] . '/app/vendor/Mustache/Autoloader.php';
	Mustache_Autoloader::register();
	
	require_once $_SERVER['DOCUMENT_ROOT'] . '/app/vendor/FrontMatter.php';
	
	require_once $_SERVER['DOCUMENT_ROOT'] . '/app/vendor/Markdown.php';
	
	require_once $_SERVER['DOCUMENT_ROOT'] . '/app/vendor/Toro.php';
	
		
	
	spl_autoload_register(function ($class) {
    	require_once $_SERVER['DOCUMENT_ROOT'] . '/app/lib/classes/' . $class . '.php';
	});
	
	////////////////////////////////////////////////////

	$config_obj = ConfigHandler::process($_SERVER['DOCUMENT_ROOT']. '/config.ini');
	
	$theme_dir = $config_obj->settings['theme'];
	
	if ($config_obj->settings['theme'] == 'default') {
		
		define('THEME_DIR', 'app/themes/'.$theme_dir);
		
	} else {
		
		define('THEME_DIR', 'themes/'.$theme_dir);

	}
	
	////////////////////////////////////////////////////
	
	ToroHook::add("404",  function() {
		ErrorMessageHandler::dispatch('404');
	});
	
	Toro::serve(array(
	    "/" => "IndexHandler",
	    "/feed" => "FeedHandler",
	    "/:alpha/feed" => "SubFeedHandler",
	    "/:alpha" => "PageHandler",
	    "/:alpha/:alpha" => "PostHandler", 
	));

};