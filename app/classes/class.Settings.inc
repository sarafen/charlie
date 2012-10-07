<?php

class Charlie_Settings {

	// PROPERTIES
	static $theme;
    static $theme_dir;
    static $maintenance_toggle;
	
	// METHODS
	public function init() {
	
		$ini = Ini::getInstance('./config.info');
	
		// Maintenance Toggle
		$setting_maintenance = strip_tags($ini->General_Info['maintenance_mode']); // ! This and others throw ERROR because of direct property access.!
		
		if ($setting_maintenance == 'ON,1') {
		
			self::$maintenance_toggle = TRUE;
		}
		
		
		// Theme
		self::$theme = strip_tags($ini->Theme_Settings['theme']); 
				
		
		// Theme Dir
		self::$theme_dir = 'themes/'.self::$theme;
						
	}
	
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
	
}
