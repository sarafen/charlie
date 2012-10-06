<?php

class Charlie_View {
	
	// PROPERTIES
	public $template;
	public $data;
	
	
	// METHODS
	public function __construct() {
	
	$this->template = 'page';
	$this->data = '';

		
	}
	
	public function render($template, $data) {
	
		$mustache = new Mustache_Engine(array(
		    'template_class_prefix' => '__MyTemplates_',
		    'cache' => dirname(__FILE__).'/tmp/cache/mustache',
		    'loader' => new Mustache_Loader_FilesystemLoader(dirname(dirname(dirname(dirname(__FILE__)))).'/themes/'.THEME),
		    'partials_loader' => new Mustache_Loader_FilesystemLoader(dirname(dirname(dirname(dirname(__FILE__)))).'/themes/'.THEME.'/partials'),
		    'escape' => function($value) {
		        return htmlspecialchars($value, ENT_COMPAT, 'UTF-8');
		    },
		));
	
	
		if (empty($template)) {$template = $this->template;}
		if (empty($data)) {$data = $this->data;}
		
		
		echo $mustache->render($template, $data);
		
	}
	
	public function get($template, $data) {
	
		$mustache = new Mustache_Engine(array(
		    'template_class_prefix' => '__MyTemplates_',
		    'cache' => dirname(__FILE__).'/tmp/cache/mustache',
		    'loader' => new Mustache_Loader_FilesystemLoader(dirname(dirname(dirname(dirname(__FILE__)))).'/themes/'.THEME),
		    'partials_loader' => new Mustache_Loader_FilesystemLoader(dirname(dirname(dirname(dirname(__FILE__)))).'/themes/'.THEME.'/partials'),
		    'escape' => function($value) {
		        return htmlspecialchars($value, ENT_COMPAT, 'UTF-8');
		    },
		));
	
		if (empty($template)) {$template = $this->template;}
		if (empty($data)) {$data = $this->data;}
		
		return $mustache->render($template,$data);
	}
	
}

