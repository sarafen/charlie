<?php

/**
  * Handles the Index Route
  * 
  */

class IndexHandler {
    
    function get() {
    
    	$type = 'page';
    
    	////////////////////////////////////////////////////
    	
    	$content_file = ContentFileHandler::get('','index',$type);

		$template = 'index.ms';
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