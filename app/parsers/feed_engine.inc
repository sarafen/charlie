<?php

// Feed ENGINE

//feed('./themes/'.$GLOBALS['theme'].'/feed.atom');

function feed_entry($file,$path) {

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
	$date = date(DATE_ATOM, filemtime($file));
	$date_year = date('Y',filemtime($file));
	
	//Assemble ID
	$id = 'tag:'.$domain.','.$date_year.':'.$path;
	$link = $domain.$path;
	
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
		  
		  
			<p>'.$teaser.'</p>
		
		  
		</div>
   </content>
</entry>

';

echo $entry;
	
	
}


function feed_looper($content_type) {
	
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
		
		//echo $filename;
		//echo "</br>";
		//md("./content/blog/".$filename);
		
		feed_entry($dir.$filename,$filename);
				
	}

}


function feed_header() {
	
	$feed_header = '<?xml version="1.0" encoding="utf-8"?>
  <feed xmlns="http://www.w3.org/2005/Atom" xml:lang="en">

  <title>Stephen Lovell\'s Blog Feed</title>
  <subtitle>Designer &#38; Thinker</subtitle>
  <link href="http://sc.dev/stacey/feed/" hreflang="en" rel="self" type="application/atom+xml"/>
  <link href="http://sc.dev/stacey/" hreflang="en" rel="alternate" type="text/html"/>
  
  <updated>2012-07-15T10:50:43+10:00</updated>
  <generator uri="http://charliecms.com/" version="1.0">Charlie</generator>

  <author>
    <name>Stephen Lovell</name>
    <uri>http://sc.dev/stacey</uri>
  </author>

  <id>tag:sc.dev,2012:/feed/</id>
  <rights> 2012 Stephen Lovell</rights>';
  
  echo $feed_header;
	
}

function feed_footer() {
	
	$feed_footer = '</feed>';
	
	echo $feed_footer;
	
}

//Set Header correctly

function feed_content($type) {

	header('Content-type: application/atom+xml');
	
	//Render FEED
	feed_header();
	feed_looper($type);
	feed_footer();
}
