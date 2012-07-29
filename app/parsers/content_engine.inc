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

	if (!empty($path_part[1]) && $path_part[2] != null && empty($path_part[3])) {
		
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

//Build ENTRY
function item($file,$path) {

	//Get URI
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

//Build LOOP
function looper($content_type) {
	
	$dir = "content/".$content_type."/";

	/*
function compare_time($a, $b) {
	
	    global $dir;
	
	    $timeA = filemtime("$dir/$a");
	    $timeB = filemtime("$dir/$b");
	
	    if($timeA == $timeB) return 0;
	
	    return ($timeA < $timeB) ? -1 : 1;
	}
*/
	
	$files = scandir($dir);
	//usort($files, 'compare_time');
	
	$files = array_diff($files, array('.', '..', '.DS_Store'));
	
	//print_r($files);
	
	
	foreach($files as $key => $val) {
	
		$filename = $val;
		
		echo item($dir.$filename,$filename);
				
	}

}
