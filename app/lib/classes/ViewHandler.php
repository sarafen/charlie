<?php

/*
 *
 * @template, @fields
 * 
 * Takes @template, @fields
 * outputs a fully glued
 * together view.
 *
 */
 
class ViewHandler {
	
	private static $view;
	
	public static function render($template,$fields) {
		
		$mustache = new Mustache_Engine(array(
		    'template_class_prefix' => '__MyTemplates_',
		    'cache' => $_SERVER['DOCUMENT_ROOT'].'/app/tmp/cache/mustache',
		    'loader' => new Mustache_Loader_FilesystemLoader($_SERVER['DOCUMENT_ROOT'].'/'.THEME_DIR),
		    'partials_loader' => new Mustache_Loader_FilesystemLoader($_SERVER['DOCUMENT_ROOT'].'/'.THEME_DIR.'/partials'),
		    'escape' => function($value) {
		        return htmlspecialchars($value, ENT_COMPAT, 'UTF-8');
		    },
		));
			
		static::$view = $mustache->render($template, $fields);
		
		echo static::$view;
		
	}
	
}