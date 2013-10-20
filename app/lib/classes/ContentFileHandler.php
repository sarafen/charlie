<?php 

/*
 * @parent, @name, @type
 *
 * Takes @parent, @name & @type
 * Pulls appropriate content file
 * based on cascade hierarchy.
 * 
 */
 
class ContentFileHandler {

	private static $content_file;
	private static $existence;
	  
	public static function get($parent,$name,$type) {
		 
		$ext = '.md';
		
		$file = glob($_SERVER['DOCUMENT_ROOT'].'/content/'.$parent.'/*.'.$name.$ext);
		if (is_array($file)) {$file = reset($file);}
	
		if (file_exists($file)) {
		
			$file = basename($file);
			static::$content_file = $parent.'/'.$file;
			static::$existence = true;
			
		}
		
		elseif (file_exists($_SERVER['DOCUMENT_ROOT'].'/content/'.$type.'s/'.$name.$ext)) {
			
			static::$content_file = $type.'s/'.$name.$ext;	
			static::$existence = true;
		}
		
		else {
		
			static::$content_file = 'pages/404'.$ext;
			static::$existence = false;
			
		}
		
		return static::$content_file;
	} 
	 
	 
	 public static function exists() {
		 		
		return static::$existence;
	 } 
 }