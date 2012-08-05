<?php

// Sets up the Config Object 

class Config {  

	// PROPERTIES
	static $theme;
    static $theme_dir;
    static $maintenance_toggle;
    static $info_handler_toggle;
    static $template_engine;
    
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
    
    public function set_template_engine($template_engine) {
	    
	    self::$template_engine = $template_engine;
    }
    
    public function  get_template_engine() {
    
	    return self::$template_engine;
	    
    }
    
    public function the_template_engine() {
    
	    echo self::$template_engine = $template_engine;
    }

} 