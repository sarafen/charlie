<?php

// Sets up the Page Object 

class Page {  

	// PROPERTIES
    private $_path;
    private $_type;
    private $_parent; //Applies to Post Pages mostly
    private $_template;
    private $_date;
    private $_title;
    private $_teaser;
    
    // METHODS       
    public function __construct() { 
    
    	//URI
    	$uri = $_SERVER['REQUEST_URI'];
		$path_part = explode('/', $uri);
		$path = end($path_part); 
		if ($path == null) {$path = prev($path_part);}
		
		//Path
        $this->_path = $path;
        
        //Type
        
        if ($path == 'feed') {
	        
	        $type = 'feed';
	        
        } else if(!empty($path) && $path == $path_part[1]) {
	        
	        $type = 'page'; 
	        
        } else if (!empty($path) && $path == $path_part[2]) {
        
	        $type = 'post';
	        
        } else if(empty($path_part[2])) {
	        $type = 'index';
	        
        } else {
        	
        	$type = '404';
	        
        } //else {$type = '404';}
        
        $this->_type = $type; 
        
        //Parent
        if ($type == 'post') {
        
        	$parent = $path_part[1];
	        
        } else {$parent = 'None';}
        
        $this->_parent = $parent;
        
        //Title
        $title = ucwords(str_replace('-', ' ', $path));
        $this->_title = $title;
    } 
    
    //public function set_path() {}
    
    public function get_path() {
	    
	    return $this->_path;
    }
    
    public function the_path() {
	    
	    echo $this->_path;
    }   
    
    public function get_type() {
	    
	    return $this->_type;
    }
    
    public function the_type() {
    
    	echo $this->_type;
    }
     
    public function get_title() {
	    
	    return $this->_title;
    }
    
    public function the_title() {
	    
	    echo $this->_title;
    }
     
    public function get_parent() {
	    
	    return $this->_parent;
    }
    
    public function the_parent() {
	    
	    echo $this->_parent;
    }

} 