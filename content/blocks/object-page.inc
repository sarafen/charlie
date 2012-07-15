<?php	

	$uri = $_SERVER['REQUEST_URI'];
	$path_part = explode('/', $uri);
	$path_end = end($path_part);

	$title = $path_end;
	$teaser="There was no sunlight, no sunlight";
	$author="Stephen Lovell";
	
		
	$page = new page($title);

	echo "<br /> Page's Title: ".$page->get_title();
	
	
	$article = new article($title,$teaser,$author);
	
	
	echo "<br /> Articles's Title: ".$article->get_title();
	echo "<br /> Articles's Teaser: ".$article->get_teaser();
	echo "<br /> Article By: ".$article->get_author();
	echo "<br />";
	
	
	
	//require ('inc/loader.inc.');
	



function view(){
		
		echo "hello world";
}


class loader {

	var $bob;



	function __construct(){
	
		
			$this->bob = view();
		
		}	
}

	
$load =& new loader;

//echo $load->view(tom);
	


	
	
	
	
	
