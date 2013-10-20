<?php 

/**
  * Handles Feed Routes
  * 
  */

class FeedHandler {

	function get() {
	
		$type = 'feed';
		$name = 'feed';
	
		////////////////////////////////////////////////////
		
		//$content_file = ContentFileHandler::get('',$name,$type);

		$template = TemplateHandler::get('',$name,$type);
		$fields = FieldHandler::get();
		
		$view = new ViewHandler();
		
		////////////////////////////////////////////////////
		
		header('Content-type: application/atom+xml');
		$view->render($template,$fields);			
	
	}
}