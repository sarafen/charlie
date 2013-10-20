<?php 

////////////////////////////////////////////////////

/*
 * @block, @pattern
 *
 * Uses Prefix Notation to parse
 * @block w/ @pattern
 *
 */
 
abstract class DotNotationFilter {
	
	private static $pattern = '/^[a-z]+\./';
	
	public static function get($block,$pattern) {
		 
		 if (is_null($pattern)) {
			 static::$pattern = $pattern;
		 }
		 
		 return static::parse($block,self::$pattern);
	}
	
	abstract protected static function parse($block,$pattern);
}
