<?php

include_once ('./app/inc/get_data.php');

function cache_money ($api_file,$cache_file,$cache_life,$src,$debug) {

	$filemtime = filemtime($cache_file);  // returns FALSE if file does not exist
	$elapse_time = (time() - $filemtime);
	
	if (!($cache_life >= $elapse_time)){
	
	    $current_data = get_data($api_file);
	    
	    if ($current_data != null) {file_put_contents($cache_file,$current_data);}	
		if ($debug != 'off'){echo 'Retrieving '.$src.' API file. ';}
		if ($current_data == null) {echo "\n".$src.' API retrieval FAILED. Using '.$src.' cache file. ';}	
	
	}
	
	else if ($debug != 'off') {echo 'Using '.$src.' cache file. ';}
	
	
	//For special treatment of different src's 
	/*
	switch ($src) {
    case 'twitter':
        echo '<script type="text/javascript">var twitter_feed = "'.$cache_file.'";</script>';
        break;
    case 'tumblr':
        echo "\n".'<script src="'.$cache_file.'"></script>';
        break;
    }
	*/

}