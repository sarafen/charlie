<?php

/*
 * @param
 *
 * Creates a Field Object
 * 
 */
 
class FieldHandler {
	
	private static $fields;

	public static function get($content_file='') {
	
		//Config File
		$path = $_SERVER['DOCUMENT_ROOT'].'/content/';
		$config_obj = ConfigHandler::getInstance();
		
		//Global Fields	
		self::$fields['current_year'] = date("Y");
		self::$fields['theme_dir'] = '/'.THEME_DIR;
		self::$fields['img_dir'] = '/content/imgs';
					
		foreach ($config_obj->globals as $key => $val) {
		
			self::$fields[$key] = $val;
		}
		
		//Loopers
		$looper = new QueryLoopHandler();
		
		foreach ($config_obj->loops as $key => $val) {		
    
		    self::$fields[$key.'_looper'] = $looper->fetch(
	    		$val['loop_type'],
	    		$val['content_type'],
	    		$val['date_format'],
	    		$val['limit']
	    	);

	    } 
	    	
		//Content File
		if (!empty($content_file))	{
			$full_content_path = $path.$content_file;
			
			//FrontMatter Fields
			$frontmatter = new FrontMatter($full_content_path);
			
			foreach ($frontmatter->data as $key => $val) {
			
				self::$fields[$key] = $val;
			}
			
			//Body Field
			$mustache = new Mustache_Engine;
			
			self::$fields['content'] = Markdown($mustache->render($frontmatter->fetch('content'), $frontmatter->data));	
		}
		
		return self::$fields;
	}	
}