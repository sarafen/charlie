<?php

//Define New Loopers

$page->blog_looper = function () {
		
	$items = looper(
		$type = 'blog',
		$date_format = 'F jS Y'
	);
	
	//return $items;
	
	return $items;

};
