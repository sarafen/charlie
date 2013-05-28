<?php

/**
  * Charlie Template
  *
  * Assembles the appropriate template based on the content viewed.
  */

class Charlie_Template {

	// PROPERTIES
	public $template;
		
	
	// METHODS
	public function __construct($page_data) {
	
		$template = '';
		$ext = '.ms';
		
		//Check for FRONT Page - Load 'index.ms'
		if ($page_data->get_type() == 'index') {
		
			 //$template = 'index.ms';
			 $template = 'index';
		}
						
		//Check for PAGE Content Type - Load 'page.tpl.php' default
		
		//Establish 'page-[pagename].ms' Template File Name Scheme
		
		//Check for PAGE Content Type - Load 'page[type].tpl.php' specific
		if 	($page_data->get_type() == 'page' && file_exists('./themes/'.THEME.'/page-'.$page_data->get_path().$ext)) {
			
			//$template = './themes/'.THEME.'/page-'.$page->get_path().'.ms';
			$template = 'page-'.$page_data->get_path();
			
		}
		
		//Fallback to default PAGE template - Load 'page.tpl.php' generic
		if ($page_data->get_type() == 'page' && !file_exists('./themes/'.THEME.'/page-'.$page_data->get_path().$ext)) {
		
			//$template ='./themes/'.THEME.'/page.ms';	
			$template = 'page';
		} 
		
		//Check for POST Content Type - Load 'post-[type].ms' specific
		if 	($page_data->get_type() == 'post' && file_exists('./themes/'.THEME.'/post-'.$page_data->get_parent().$ext)) {
			
			//$template = './themes/'.THEME.'/post-'.$page->get_parent().'.ms';
			$template = 'post-'.$page_data->get_parent();
		}
		
		//Check for FEED Content Type - Load 'feed.ms'
		if ($page_data->get_type() == 'feed' && empty($path)) {
		
			 //$template = './themes/'.THEME.'/feed.ms';
			 //include $template;
			 
			 $template = 'feed';	 
		}
		
		$this->template = $template;
	
	}
	
	public function fetch() {
	
		return $this->template;
	
	}
	
	public function set($template) {
		
		$this->template = $template;
	}
	
}
