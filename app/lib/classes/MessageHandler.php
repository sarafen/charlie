<?php

/*
 * @type
 *
 * Outputs Message based on @type
 *
 */

abstract class MessageHandler {
	
	protected static $type;
		
	public static function dispatch($type) {
		
		static::RenderMessage($type);
		
	}
	
	abstract protected static function RenderMessage($type);
	
}