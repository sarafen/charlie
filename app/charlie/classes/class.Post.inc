<?php


// Sets up the Page Object 




function get_Type() {
	
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
        
    }
    
    $this->_type = $type; 


	
}


switch ($this->_type) {
		
		    case "index":
		        $file = './content/pages/front.md';
		        break;
		        
		    case "page":
		        $file = './content/pages/'.$path_part[1].'.md';
		        break;
		        
		    case "post":
		        $file = glob('./content/'.$path_part[1].'/*.'.$path_part[2].'.md');
		        if (is_array($file)) {$file = reset($file);}
		        break;
		        
			case "404":
				$file = './content/pages/404.md';
				break;
		}















































class Charlie_Post {

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
        
 
        
             
        //Establish the file we are working with for CONTENT			
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
		
					
		//Include the Appropriate Content & Fields		
		if (file_exists($file) && $file != null) {
				
			$fm = new FrontMatter($file);
			$m = new Mustache_Engine;
			
			//Include frontmatter fields
			foreach ($fm->data as $key => $value) {
			
				$this->$key = $value;
	        }
			
			//Treat the Content field with Markdown and Mustache
			$this->content = Markdown($m->render($fm->fetch('content'), $fm->data));
		
		} 
		
		else if (file_exists('./content/pages/404.md') && $path_part[1] != 'feed') { //do better job of feed error handling
			//include THEME_DIR.'/404.tpl.php';
			//$this->content = file_get_contents('./content/pages/404.md');
			
			header('HTTP/1.0 404 Not Found'); 
			$this->content = return_md('./content/pages/404.md');
		}
		
		else if ($path_part[1] != 'feed') { //do better job of feed 404 handling
		
			//include './themes/default/404.tpl.php';
			//$this->content = file_get_contents('./themes/default/404.tpl.php');
			
			header('HTTP/1.0 404 Not Found'); 
			$this->content = return_md('./app/charlie/404.php');
		}
