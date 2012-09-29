<?php

//Build base POST
function the_post($file,$path,$content_type,$date_format) {

	//Get frontmatter
	$post_fm = new FrontMatter($file);
	
	//Get Path
	$info = pathinfo($path);
	$path = basename($path,'.'.$info['extension']);
	$path = preg_replace("/^[0-9\\.\\s]+/", '', $path);
	$path = '/'.$content_type.'/'.$path.'/';

	//$file = "./content/blog/one.md";
	$html = return_md($file);

	//Get TITLE
    preg_match_all("/<h1>(.*?)<\/h1>/", $html, $matches);
    $title = $matches[1][0];
    
	
	//Get DATE
	$date = date($date_format, filemtime($file));
	
	$link = DOMAIN.$path;
	
	//Get TEASER
	preg_match_all("/<p>(.*?)<\/p>/", $html, $matches);
    $teaser = $matches[1][0];
			
	//$postObject = array();
	$postObject = $post_fm->data;
	
	
	//$postObject['title'] = $post_fm->fetch('title');
	//$postObject['teaser'] = $teaser;
	$postObject['link'] = $link;
	//$postObject['date'] = $post_fm->fetch('date');

	return $postObject;
}

//Build base LOOPER   
function looper($content_type,$date_format = 'l jS \of F Y h:i:s A') {
	    
    //Render LOOP
	//$content_type = 'blog'; //testing
	$dir = "content/".$content_type."/";
	$files = scandir($dir);
	$files = array_reverse($files);
	//usort($files, 'compare_time');
	$files = array_diff($files, array('.', '..', '.DS_Store','imgs'));
		
	$items = array('items' => array());
	
	$i = 0;
	
	foreach($files as $key => $val) {
	
		$filename = $val;
		$num = $i++;
			
		$items['item'][$num] = the_post($dir.$filename,$filename,$content_type,$date_format);
									
	}
	
	return $items;		    
    
}