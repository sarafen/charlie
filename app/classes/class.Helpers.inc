<?php

class Charlie_Helpers {


	// METHODS
	static function md($file) {
	
		$raw_content = file_get_contents($file); $content = Markdown($raw_content);
		
		echo $content;
	
	}
	
	static function return_md($file) {
	
		$raw_content = file_get_contents($file); $content = Markdown($raw_content);
		
		return $content;
	
	}
	
		
}