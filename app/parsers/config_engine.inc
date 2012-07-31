<?php

// Config ENGINE

////////////////////////////////////////////////////

// Include CLASSES

////////////////////////////////////////////////////

require_once "./app/classes/class.ini_settings.inc";
require_once "./app/classes/class.config_settings.inc";

////////////////////////////////////////////////////

// Parse & Pass In INI SETTINGS

////////////////////////////////////////////////////
 
$settings = Settings::getInstance('./app/config.info');

	//General Info
	$setting_maintenance = strip_tags($settings->General_Info['maintenance_mode']); // ! This and others throw ERROR because of direct property access.!
	
	if ($setting_maintenance == 'ON,1') {
	
		$setting_maintenance = TRUE;
	}
	
	$setting_info_handler = strip_tags($settings->General_Info['info_handler']);
	
	if ($setting_info_handler == 'ON,1') {
	
		$setting_info_handler = TRUE;
	}
	
	//Theme Settings
	$theme = strip_tags($settings->Theme_Settings['theme']); 


////////////////////////////////////////////////////

// Set THEME directory

////////////////////////////////////////////////////

$theme_dir = 'themes/'.$theme;

function get_theme_dir() {

	$site_url = $_SERVER['SERVER_NAME'];

	echo 'http://'.$site_url.'/'.Config::get_theme_dir();;

};

////////////////////////////////////////////////////

// Set Default THEME.

////////////////////////////////////////////////////

if (!file_exists($theme_dir) && !is_dir($theme_dir)) {

	$theme = "default";
	
}

////////////////////////////////////////////////////

// Pass INI Settings to Config Object.

////////////////////////////////////////////////////

/*
define('CONFIG', 'configuration');

${CONFIG} = new Config();

function charlie() {
    return $GLOBALS[CONFIG];
}


charlie()->set_theme($theme);
charlie()->set_theme_dir($theme_dir);
charlie()->set_maintenance_toggle($settings_maintenance);
charlie()->set_info_handler_toggle($setting_info_handler);
*/


Config::set_theme($theme);
Config::set_theme_dir($theme_dir);
Config::set_maintenance_toggle($setting_maintenance);
Config::set_info_handler_toggle($setting_info_handler);


////////////////////////////////////////////////////

// Establish the primitive TEMPLATE Assembly.

////////////////////////////////////////////////////

$header = 'themes/'.Config::get_theme().'/header.tpl.php';
$footer = 'themes/'.Config::get_theme().'/footer.tpl.php';

////////////////////////////////////////////////////

// Define CONSTANTS

////////////////////////////////////////////////////

define('THEME', Config::get_theme());
define('THEME_DIR', Config::get_theme_dir());
define('HEADER', $header);
define('FOOTER', $footer);
define('INFO_HANDLER_TOGGLE', Config::get_info_handler_toggle());
define('MAINTENANCE_TOGGLE',  Config::get_maintenance_toggle());

//$GLOBALS["theme"]=Config::get_theme();
//$GLOBALS["theme_dir"]=Config::get_theme_dir();
//$GLOBALS["header"]=$header;
//$GLOBALS["footer"]=$footer;	
//$GLOBALS["setting_info_handler"]=Config::get_info_handler_toggle();
//$GLOBALS["setting_maintenance"]=Config::get_maintenance_toggle();
