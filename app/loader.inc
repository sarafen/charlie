<?php



define('PATH', 'inc/');

class Loader { 

/////////////////////////////////////
//  PROPERTIES
/////////////////////////////////////

protected $view_paths 	= array();
     
    
/////////////////////////////////////
//  METHODS	
/////////////////////////////////////
    
	
	public function __construct() {           
		$this->view_paths = array(PATH.'views/' => TRUE);
	}
	

	
	public function view($view, $vars = array();, $return = FALSE) {
	
		return $this->load(array('view' => $view, 'vars' => $this->_object_to_array($vars), 'return' => $return));
	
	}
	
	
	protected function load($data){
	
		foreach (array('view','vars','path','return') as $val) {
			
		}
	
	}
	
}


