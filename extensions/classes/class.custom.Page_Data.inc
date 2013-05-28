<?php

/**
  * Page Data
  *
  * Setup to allow Custom Data manipulation.
  * 
  * Will be deprecated in favor of INI Settings options.
  */

// Sets up the Page Object 
class Page_Data extends Charlie_Page_Data {
 
	public function __construct($path) {
		
		parent::__construct($path);
				
	}
	
}