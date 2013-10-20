<?php 

/**
  * Handles Page Routes
  * 
  */

class PageHandler {

	function get($name) {
	
		$type = 'page';
	
		////////////////////////////////////////////////////
		
		$content_file = ContentFileHandler::get('',$name,$type);

		$template = TemplateHandler::get('',$name,$type);
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