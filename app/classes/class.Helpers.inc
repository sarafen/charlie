<?php

/**
 * Charlie Helpers
 * 
 * Adds Helper functions to Charlie. 
 * 
 * Remove Class altogether at some point, as it's rather bad convetion if I go strict OOP.
 */

class Charlie_Helpers {

 
	//METHODS
	
	static function md($file) {
	
		$raw_content = file_get_contents($file); $content = Markdown($raw_content);
		
		echo $content;
	
	}
	
	static function return_md($file) {
	
		$raw_content = file_get_contents($file); $content = Markdown($raw_content);
		
		return $content;
	
	}
	
		
}