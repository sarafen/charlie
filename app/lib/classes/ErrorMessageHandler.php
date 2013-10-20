<?php

/*
 * @type
 *
 * Outputs Error Message based
 * on @type
 *
 */
  
class ErrorMessageHandler extends MessageHandler {	
	
	protected static function RenderMessage($type) {
	
		switch ($type) {
   			case '404':
        		header('HTTP/1.1 404 Not Found');
        		
        		$content_file = ContentFileHandler::get('','404','page');
        		
				$template = TemplateHandler::get('','404','page');
				$fields = FieldHandler::get($content_file);
				
				$view = new ViewHandler();
				        		
        		//echo $view;
        		$view->render($template,$fields);
        		
        		//die;		
        	break;
	
        }
	}
}