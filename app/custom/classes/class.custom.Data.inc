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
		
		$items = $this->looper(
			$type = 'blog',
			$date_format = 'F jS Y'
		);
		
		return $items;
	
	}
	
	//Work LOOPER
	public function work_looper() {
		
		$items = $this->looper(
			$type = 'work',
			$date_format = 'F jS Y'
		);
		
		return $items;
	}


}