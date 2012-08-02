<?php

// Sets up the View Data Object 

class viewData {  

	// PROPERTIES
	public $name = 'Bob'; 
	public $title = 'Sir';
	public $content;
	//public $header;
	   
    // METHODS 
    
    
  	public function __construct() { 
  	
  		//$this->header = file_get_contents('./themes/tesla/partials/header.mustache');
  		$this->content = return_md('./content/pages/front.md');
  	}
  	
  	  	
    
} 