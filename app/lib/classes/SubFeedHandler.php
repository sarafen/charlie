<?php 

/**
  * Handles Feed Routes
  * 
  */

class SubFeedHandler {

	function get($name) {
	
		$type = 'feed';
		$parent = 'feed';
	
		////////////////////////////////////////////////////
		
		$template = TemplateHandler::get($parent,$name,$type);
		$fields = FieldHandler::get();
		
		$view = new ViewHandler();
		
		////////////////////////////////////////////////////
		
		if ($template != 'feed') {

			header('Content-type: application/atom+xml');
			$view->render($template,$fields);
					
		} else {
		
			
			ErrorMessageHandler::dispatch('404');
					
		}			
	}
}