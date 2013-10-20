<?php

/*
 * @array, @pattern
 *
 * Uses Prefix Notation to parse
 * @array w/ @pattern
 *
 * Ex: | array(foo.bar => array()); | --> | array(foo => array(bar => array())); |
 *
 */
 
class ArrayDotNotationFilter extends DotNotationFilter {

	protected static function parse($array,$pattern) {
		
		foreach($array as $key => $val) {
			
			if(preg_match($pattern, $key, $matches)) {
			
				$unprefixed_key = trim($key, $matches[0]);
				
				$plural_pattern = trim($matches[0],'.').'s';
				
				$array[$plural_pattern][$unprefixed_key] = $val;
				
				unset($array[$key]);
			}
		}
		
		return $array;
	}
}
