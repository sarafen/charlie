<?php

// Sets up the Page Object 
class Data extends Charlie_Data { 

	public function __construct() {
		
		parent::__construct();
		
		//custom construct stuff here
			
	}
	
	// Build Custom LOOPERS
	
	//Blog LOOPER
	public function blog_looper() {
		
		$items = looper(
			$type = 'blog',
			$date_format = 'F jS Y'
		);
		
		return $items;
	
	}
	
	//Work LOOPER
	public function work_looper() {
		
		$items = looper(
			$type = 'work',
			$date_format = 'F jS Y'
		);
		
		return $items;
	}


}