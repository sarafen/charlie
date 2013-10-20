<?php

/**
  * @ini_file
  *
  * Processes an INI config file, 
  * applies a dot notation filter,
  * and outputs an Object of
  * associated configuration data.
  *
  */

class ConfigHandler { 

    private static $instance; 
    private $config; 
   
    
    private function __construct($ini_file) { 
    	
    	$parsed_ini = parse_ini_file($ini_file, true);
        $this->config = ArrayDotNotationFilter::get($parsed_ini,'');     
    } 
    
    public static function process($ini_file) { 
        if(! isset(self::$instance)) { 
            self::$instance = new ConfigHandler($ini_file);            
        } 
        return self::$instance; 
    }
    
    public function getInstance() {
	    
	    return self::$instance;
    } 
    
    public function __get($setting) { 
        if(array_key_exists($setting, $this->config)) { 
            return $this->config[$setting]; 
        } else { 
            foreach($this->config as $section) { 
                if(array_key_exists($setting, $section)) { 
                    return $section[$setting]; 
                } 
            } 
        } 
    }     
} 
