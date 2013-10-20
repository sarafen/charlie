<?php

/*
 * @parent, @name, @type
 *
 * Takes @parent, @name & @type
 * Pulls appropriate template
 * based on cascade hierarchy.
 * 
 */
 
class TemplateHandler {
	
	private static $template;

	public static function get($parent,$name,$type) {
	
		$ext = '.ms';
		
		if 	(file_exists($_SERVER['DOCUMENT_ROOT'].'/'.THEME_DIR.'/'.$type.'-'.$parent.$ext)) {
			
			static::$template = $type.'-'.$parent;			
		}
					
		elseif (file_exists($_SERVER['DOCUMENT_ROOT'].'/'.THEME_DIR.'/'.$type.'-'.$name.$ext)) {
			
			static::$template = $type.'-'.$name;	
		}
		
		else {
		
			static::$template = $type;
			
		}	
		
		return static::$template;
	}
}