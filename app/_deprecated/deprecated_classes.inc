<?php

class settings { 

/////////////////////////////////////
//  PROPERTIES
/////////////////////////////////////

    private static $instance; 
    private $settings; 
    
/////////////////////////////////////
//  METHODS	
/////////////////////////////////////
    
    private function __construct($ini_file) { 
        $this->settings = parse_ini_file($ini_file, true); 
    } 
    
    public static function getInstance($ini_file) { 
        if(! isset(self::$instance)) { 
            self::$instance = new Settings($ini_file);            
        } 
        return self::$instance; 
    } 
    
    public function __get($setting) { 
        if(array_key_exists($setting, $this->settings)) { 
            return $this->settings[$setting]; 
        } else { 
            foreach($this->settings as $section) { 
                if(array_key_exists($setting, $section)) { 
                    return $section[$setting]; 
                } 
            } 
        } 
    }     
} 
 

class page {

/////////////////////////////////////
//  PROPERTIES
/////////////////////////////////////

	var $title;
		
/////////////////////////////////////
//  METHODS	
/////////////////////////////////////

	function __construct($pages_title) {           
		$this->title = $pages_title;            
	}
	
//	 
	
//	function set_title($new_title) {
// 		$this->title = $new_title;
//	}
	
//
	
	function get_title() {
        return $this->title;
	}
}



class article extends page {

/////////////////////////////////////
//  PROPERTIES
/////////////////////////////////////

	var $teaser;
	var $author;
	var $category;
	var $tags;
		
/////////////////////////////////////	
//  METHODS	
/////////////////////////////////////

	function __construct($articles_title,$articles_teaser,$articles_author) {           
		$this->title = $articles_title;  
		$this->teaser = substr($articles_teaser, 0, 25).'...<a href="#">more</a>';
		$this->author = $articles_author;            
	} 

//
	
//	function set_title($new_title) {
// 		$this->title = $new_title;
//	}
	
//	function set_teaser($new_teaser) {
//		$this->teaser = substr($new_teaser, 0, 25).'...<a href="#">more</a>';
//	}
	
//	function set_author($new_author) {
//		$this->author = $new_author;
//	}
	
//	
	
	function get_title() {
        return $this->title;
	}
	
	function get_teaser() {
        return $this->teaser;
	}
	
	function get_author() {
        return $this->author;
	}
} 
