<?php 

class Charlie_Route {

	// PROPERTIES
	public $uri;
	public $path;
	public $path_part;
	
		
	// METHODS
	public function __construct() {
		
		// Set URI
		$this->uri = $_SERVER['REQUEST_URI'];
		
		$path_part = explode('/', $this->uri);
		$this->path_part = $path_part; 
		
		$path = end($path_part); 
		
		if ($path == null) {$path = prev($path_part);}
    
		// Set PATH
		$this->path = $path;
		
	}	
	
		
	public function get_uri() {
		
		return $this->uri;
	}
	
	public function get_path() {
		
		return $this->path;
	}
	
	public function get_parth_part() {
		
		return $this->path_part;
	}
}