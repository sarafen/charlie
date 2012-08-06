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
		
		/*
else if (file_exists(THEME_DIR.'/404.tpl.php')) {
			//include THEME_DIR.'/404.tpl.php';
			$this->content = file_get_contents(THEME_DIR.'/404.tpl.php');
		}
*/
		
		else if (file_exists('./content/pages/404.md') && $path_part[1] != 'feed') { //better job of feed error handling
			//include THEME_DIR.'/404.tpl.php';
			//$this->content = file_get_contents('./content/pages/404.md');
			
			header('HTTP/1.0 404 Not Found'); 
			$this->content = return_md('./content/pages/404.md');
		}
		
		else if ($path_part[1] != 'feed') { //better job of feed 404 handling
		
			//include './themes/default/404.tpl.php';
			//$this->content = file_get_contents('./themes/default/404.tpl.php');
			
			header('HTTP/1.0 404 Not Found'); 
			$this->content = return_md('./themes/default/404.tpl.php');
		}	     
    } 
    
    //Used for tweet.js for custom caching
    public function news() {

		include_once('./app/inc/cache_flow.php');
		
		cache_money(
			'https://api.twitter.com/1/statuses/user_timeline.json?screen_name=stephencreates&count=40&page=1&include_entities=1&callback=?', //API src
			'./cache/twitter.js', //Cache file dir
			'1000', //Cache life in seconds
			'twitter',//Cache src format
			'off' //debug?
			);
	}

	//Build LOOP
	public function looper() {
	
			
		//Build POST
		function the_post($file,$path,$content_type) {
		
			//Get URI
			
			//URI
	    	
			//$domain = 'http://charlie.dev'; //need to get more dynamically.
			
			//Get Path
			$info = pathinfo($path);
			$path = basename($path,'.'.$info['extension']);
			$path = '/'.$content_type.'/'.$path.'/';
		
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
			$link = DOMAIN.$path;
			
			//Get TEASER
			preg_match_all("/<p>(.*?)<\/p>/", $html, $matches);
		    $teaser = $matches[1][0];
					
			$postObject = array();
			
			$postObject['title'] = $title;
			$postObject['teaser'] = $teaser;
			$postObject['link'] = $link;
			$postObject['date'] = $date;
				
			return $postObject;		
			
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
			$postObject = the_post($dir.$filename,$filename,$content_type);
				
		
			$items['item'][$num] = array(
				'title' => $postObject['title'],
				'link' => $postObject['link'],
				'date' => $postObject['date'],
				'teaser' => $postObject['teaser']
			);
													
		}
		
		return $items;		
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
			
			//echo $entry;
			//return $entry;			
			
		}
			
		$dir = "content/".$content_type."/";
		
		$files = scandir($dir);
		//usort($files, 'compare_time');
		
		$files = array_diff($files, array('.', '..', '.DS_Store'));
		
		//print_r($files);
		
		
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