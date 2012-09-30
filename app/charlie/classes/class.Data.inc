<?php

// Sets up the Page Object 

class Charlie_Data {  

	// PROPERTIES
    private $_path;
    private $_type;
    private $_parent; //Applies to Post Pages mostly
    private $_content_file;
    private $_template;
    private $_date;
    private $_teaser;
    
	public $theme_dir;
	public $title;
	public $content;
		
	public $current_year;
	
    
    // METHODS       
    public function __construct() { 
    	
		//////////////////////////////////////////////
        //
        // Path
        //
        //////////////////////////////////////////////
        
        //URI
    	$uri = $_SERVER['REQUEST_URI'];
		$path_part = explode('/', $uri);
		$path = end($path_part); 
		if ($path == null) {$path = prev($path_part);}
        
        $this->_path = $path;
        
        //////////////////////////////////////////////
        //
        // Type
        //
        //////////////////////////////////////////////
        
        if ($path == $path_part[1] && $path == 'feed') {
	        
	        $type = 'feed';
	        
        } else if(!empty($path) && $path == $path_part[1] && $path_part[1] != '404') {
	        
	        $type = 'page'; 
	        
        } else if (!empty($path) && $path == $path_part[2]) {
        
	        $type = 'post';
	        
        } else if(empty($path_part[2])) {
        
	        $type = 'index';
	        
        }
        
        $this->_type = $type;
        
        //////////////////////////////////////////////
        //
        // Parent
        //
        //////////////////////////////////////////////
        
        if ($type == 'post') {
        
        	$parent = $path_part[1];
	        
        } else {$parent = 'None';}
        
        $this->_parent = $parent;
        
        //////////////////////////////////////////////
        //
        // Theme Dir // Should be moved to config
        //
        //////////////////////////////////////////////
        
        $this->theme_dir = 'http://'.$_SERVER['SERVER_NAME'].'/themes/'.THEME;
        
        //////////////////////////////////////////////
        //
        // Content File
        //
        //////////////////////////////////////////////
			
		$file = "";
					 
		//Check for FRONT Page
		if ($path_part[1] == null || !isset($path_part[1])) {
		
			$file = './content/pages/front.md';			
		}
				
		//Check for [ANYTHING] Content Type - leading slug
		if (!empty($path_part[1]) && $path_part[2] != null && empty($path_part[3])) { //wierd offset bug here only on 404.
			
			//$file = './content/'.$path_part[1].'/'.$path_part[2].'.md';
			$file = glob('./content/'.$path_part[1].'/*.'.$path_part[2].'.md');
			
			if (is_array($file)) {$file = reset($file);}	
						
		} 
			 
		//Check for PAGE Content Type - No leading slug
		if (empty($path_part[2]) && $path_part[1] != null && empty($path_part[3])) {
		
			$file = './content/pages/'.$path_part[1].'.md';	
					
		}		
			
		$this->_content_file = $file;
			
		//////////////////////////////////////////////
        //
        // Title Default (before frontmatter)
        //
        //////////////////////////////////////////////
 
	    $this->title = ucwords(str_replace('-', ' ', $path));

		//////////////////////////////////////////////
        //
        // Frontmatter Fields
        //
        //////////////////////////////////////////////
        
        if (file_exists($this->_content_file)) {
		
			$fm = new FrontMatter($this->_content_file);
			
			foreach ($fm->data as $key => $value) {
			
				$this->$key = $value;
			}
		
		}
				
		//////////////////////////////////////////////
        //
        // Content
        //
        //////////////////////////////////////////////
					
		//Include Content & Parse Inline Fields		
		if (file_exists($this->_content_file) && $this->_content_file != null) {
				
			$m = new Mustache_Engine;
			
			//Treat the Content field with Markdown and Mustache
			$this->content = Markdown($m->render($fm->fetch('content'), $fm->data));
		
		} 
		
		else if (file_exists('./content/pages/404.md') && $path_part[1] != 'feed') { //do better job of feed error handling
			
			header('HTTP/1.0 404 Not Found'); 
			$this->content = return_md('./content/pages/404.md');
		}
		
		else if ($path_part[1] != 'feed') { //do better job of feed 404 handling
					
			header('HTTP/1.0 404 Not Found'); 
			$this->content = return_md('./app/charlie/404.php');
		}
		
		//////////////////////////////////////////////
        //
        // Date(s)
        //
        //////////////////////////////////////////////
        
		$this->current_year = date("Y"); 				
    } 
    
   
   
   
   
   
   
   
   
   // Feed LOOPER	
   public function feed_looper() {
	
		$content_type = 'blog';
	
		function feed_item($file,$path) {
		
			//Get URI
			//$domain = 'http://charlie.dev';
			
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
			$date = date(DATE_ATOM, filemtime($file));
			$date_year = date('Y',filemtime($file));
			
			//Assemble ID
			$id = 'tag:'.DOMAIN.','.$date_year.':'.$path;
			$link = DOMAIN.$path;
			
			//Get TEASER
			preg_match_all("/<p>(.*?)<\/p>/", $html, $matches);
		    $teaser = $matches[1][0];
					
			//Render ENTRY
			$entry = '
				<entry>
				<title>'.$title.'</title>
				<id>'.$id.'</id>
				<updated>'.$date.'</updated>
				<link rel="alternate" type="text/html" href="'.$link.'" />
				<content type="xhtml" xml:lang="en">
					<div xmlns="http://www.w3.org/1999/xhtml">
					  
					  
						<summary>'.$teaser.'</summary>
					
					  
					</div>
			   </content>
			</entry>
			
			';
			
			$feed_entryObject = array();
				
			$feed_entryObject['entry'] = $entry;
			
			return $feed_entryObject;					
			
		}
			
		$dir = "content/".$content_type."/";
		
		$files = scandir($dir);
		//usort($files, 'compare_time');
		
		$files = array_diff($files, array('.', '..', '.DS_Store','imgs'));
		
		$items = array('items' => array());
	
		$i = 0;
		
		foreach($files as $key => $val) {
		
			$filename = $val;
			$num = $i++;
			$feed_entryObject = feed_item($dir.$filename,$filename);
				
		
			$items['item'][$num] = array(
				'entry' => $feed_entryObject['entry']
			);
													
		}
		
		header('Content-type: application/atom+xml');
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