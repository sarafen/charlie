<?php

// Sets up the Page Object 

class Page {  

	// PROPERTIES
    private $_path;
    private $_type;
    private $_parent; //Applies to Post Pages mostly
    private $_template;
    private $_date;
    private $_teaser;
    
	public $theme_dir;
	public $title;
	public $content;
	
    
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
        $this->title = $title;
        
        //Theme_dir
        $this->theme_dir = 'http://charlie.dev/themes/'.THEME;
        
        
        //Content			
		$file = "";
		 
		//Check for FRONT Page
		
		if ($path_part[1] == null || !isset($path_part[1])) {
		
			$file = './content/pages/front.md';		 
		}
				
		//Check for [ANYTHING] Content Type - leading slug
	
		if (!empty($path_part[1]) && $path_part[2] != null && empty($path_part[3])) { //wierd offset bug here.
			
			$file = './content/'.$path_part[1].'/'.$path_part[2].'.md';		 
		} 
		
			 
		//Check for PAGE Content Type - No leading slug
		
		if (empty($path_part[2]) && $path_part[1] != null && empty($path_part[3])) {
		
			$file ='./content/pages/'.$path_part[1].'.md';			
		}
			
		//Include the Appropriate Content		
		
		if (file_exists($file) && $file != null) {
		
		$this->content = return_md($file);
		} 
		
		else if (file_exists(THEME_DIR.'/404.tpl.php')) {
			//include THEME_DIR.'/404.tpl.php';
			$this->content = file_get_contents(THEME_DIR.'/404.tpl.php');
		}
		
		else {
		
			//include './themes/default/404.tpl.php';
			$this->content = file_get_contents('./themes/default/404.tpl.php');
		}	
        
        
    } 
    
    
    
	
	//Build LOOP
	public function blog_looper($content_type) {
	
		//Build ENTRY
		function item($file,$path) {
		
			//Get URI
			
			//URI
	    	
			$domain = 'http://charlie.dev';
			
			//Get Path
			$info = pathinfo($path);
			$path = basename($path,'.'.$info['extension']);
			$path = '/blog/'.$path.'/';
		
			//$file = "./content/blog/one.md";
			$html = return_md($file);
		
			//Get TITLE
		    preg_match_all("/<h1>(.*?)<\/h1>/", $html, $matches);
		    $title = $matches[1][0];		
			
			
			//Get DATE
			$date = date('l jS \of F Y h:i:s A', filemtime($file));
			//$date_year = date('Y',filemtime($file));
			
			//Assemble ID
			//$id = 'tag:'.$domain.','.$date_year.':'.$path;
			$link = $domain.$path;
			
			//Get TEASER
			preg_match_all("/<p>(.*?)<\/p>/", $html, $matches);
		    $teaser = $matches[1][0];
			
		
			//Render ENTRY
			$item = '
				<h2><a href="'.$link.'" >'.$title.'</a></h2>
				<span>'.$date.'</span>
					  
						<p>'.$teaser.'</p>
					  
			';
			
			return $item;	
		}
	
	
	
	
		//Render LOOP
		
		$content_type = 'blog'; //testing
		
		$dir = "content/".$content_type."/";
		
		$files = scandir($dir);
		
		$files = array_diff($files, array('.', '..', '.DS_Store'));
		
		//print_r($files);
		
		$items = array('items' => array());
		
		$i = 0;
		
		foreach($files as $key => $val) {
		
			$filename = $val;
			$num = $i++;		
			
			$items['items'][$num] = array('item' => item($dir.$filename,$filename));
													
		}
		
		return $items;		
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
    
    public function set_content($content) {
	    
	    $this->content = $content;
    }

} 