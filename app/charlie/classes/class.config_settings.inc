<?php

// Sets up the Config Object 

class Charlie_Config {  

	// PROPERTIES
	static $theme;
    static $theme_dir;
    static $maintenance_toggle;
    static $info_handler_toggle;
    
    // METHODS 
             
    public function set_theme($theme) {
	    
	    self::$theme = $theme;
    }
    
    public function get_theme() {
	    
	    return self::$theme;
    }
    
    public function the_theme() {
	    
	    echo self::$theme;
    }   
    
    public function set_theme_dir($theme_dir) {
	    
	    self::$theme_dir = $theme_dir;
    }
    
    public function get_theme_dir() {
	    
	    return self::$theme_dir;
    }
    
    public function the_theme_dir() {
    
    	echo self::$theme_dir;
    }
    
    public function set_maintenance_toggle($maintenance_toggle) {
	    
	    self::$maintenance_toggle = $maintenance_toggle;
    }
     
    public function get_maintenance_toggle() {
	    
	    return self::$maintenance_toggle;
    }
    
    public function the_maintenance_toggle() {
	    
	    echo self::$maintenance_toggle;
    }
    
    public function set_info_handler_toggle($info_handler_toggle) {
	    
	    self::$info_handler_toggle = $info_handler_toggle;
    }
     
    public function get_info_handler_toggle() {
	    
	    return self::$info_handler_toggle;
    }
    
    public function the_info_handler_toggle() {
	    
	    echo self::$info_handler_toggle;
    } 
} 