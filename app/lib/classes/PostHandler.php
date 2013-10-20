<?php

/**
  * Handles Post Routes
  * 
  */

class PostHandler {

	function get($parent,$name) {
	
		$type = 'post';
		
		////////////////////////////////////////////////////
		
		$content_file = ContentFileHandler::get($parent,$name,$type);
		
		$template = TemplateHandler::get($parent,$name,$type);
		$fields = FieldHandler::get($content_file);
		
		$view = new ViewHandler();
		
		////////////////////////////////////////////////////
		
		if (ContentFileHandler::exists() == true) {
			
			$view->render($template,$fields);
					
		} else {
			
			ErrorMessageHandler::dispatch('404');
	
		}
	}	
}