<?php

////////////////////////////////////////////////////

// Construct the basic CONTENT region.

////////////////////////////////////////////////////

// This section needs expansion to accomodate broader
// customization. AND allow more flexible MD conversion.

function get_content() {	

	//Grab the URL
	$uri = $_SERVER['REQUEST_URI'];
	$path_part = explode('/', $uri);
	$path = end($path_part);
	
	$file = "";
	 
	//Check for FRONT Page
	
	if ($path_part[1] == null || !isset($path_part[1])) {
	
		$file = './content/pages/front.md';		 
	}
			
	//Check for [ANYTHING] Content Type - leading slug

	if (isset($path_part[1]) && $path_part[2] != null && empty($path_part[3])) {
		
		$file = './content/'.$path_part[1].'/'.$path_part[2].'.md';		 
	} 
	
		 
	//Check for PAGE Content Type - No leading slug
	
	if (empty($path_part[2]) && $path_part[1] != null && empty($path_part[3])) {
	
		$file ='./content/pages/'.$path_part[1].'.md';			
	}
		
	//Include the Appropriate Content		
	
	if (file_exists($file) && $file != null) {md($file);} 
	
	else if (file_exists($GLOBALS["theme_dir"].'/404.tpl.php')) {
		include $GLOBALS["theme_dir"].'/404.tpl.php';
	}
	
	else {include './themes/default/404.tpl.php';}	
};

////////////////////////////////////////////////////

// Construct the robust CONTENT loop.

////////////////////////////////////////////////////


// This would be used like a diet version of the WP loop system. 
