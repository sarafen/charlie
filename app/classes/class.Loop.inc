<?php

/**
 * Charlie Loop
 *
 * Allows for the creation of dynamic Post loops similar to a light version
 * of the WordPress Loop. Loops are either standard or as a feed.
 */

class Charlie_Loop {
		
	public function __construct() {
				
	}
	
	private function the_post($file,$path,$content_type,$date_format,$loop_type) {
				
		//Get frontmatter
		$post_fm = new FrontMatter($file);
		
		//Get Path
		$info = pathinfo($path);
		$path = basename($path,'.'.$info['extension']);
		$path = preg_replace("/^[0-9\\.\\s]+/", '', $path);
		$path = '/'.$content_type.'/'.$path.'/';
	
		//$file = "./content/blog/one.md";
		$html = Charlie_Helpers::return_md($file);
	
		//Get TITLE
	    preg_match_all("/<h1>(.*?)<\/h1>/", $html, $matches);
	    $title = $matches[1][0];
	    
		//Get LINK
		$link = DOMAIN.$path;
		
		//Assemble ID
		$id = 'tag:'.DOMAIN.','.date('Y',filemtime($file)).':'.$path;
		$link = DOMAIN.$path;
		
		//Get TEASER
		preg_match_all("/<p>(.*?)<\/p>/", $html, $matches);
	    $teaser = $matches[1][0];
				
		//$postObject = array();
		$postObject = $post_fm->data;
		
		
		//$postObject['title'] = $post_fm->fetch('title');
		$postObject['teaser'] = $teaser;
		$postObject['link'] = $link;
		$postObject['id'] = $id;
		
		$date = $postObject['date'];
		list($month, $day, $year) = explode('/', $date);
		$timeStamp = mktime(0, 0, 0, $month, $day, $year);
		
		$date = date($date_format,$timeStamp);
		
		if ($loop_type == 'feed') {
			$date = date(DATE_ATOM, $timeStamp);		
		}
		
		$postObject['date'] = $date;
	
		return $postObject;
	}

	
	public function fetch($loop_type = 'default',$content_type,$date_format = 'l jS \of F Y h:i:s A',$limit='0') {
		
		//Build single POST
			

	    //Render LOOP
		$dir = "content/".$content_type."/";
		$files = scandir($dir);
		$files = array_reverse($files);
		//usort($files, 'compare_time');
		$files = array_diff($files, array('.', '..', '.DS_Store','imgs'));
			
		$items = array('items' => array());
		
		$i = 0;
		
		foreach($files as $key => $val) {
		
			$filename = $val;
			$num = $i++;
			
			$items['item'][$num] = $this->the_post($dir.$filename,$filename,$content_type,$date_format,$loop_type);		
			
			if($i!=0 && $i==$limit) break;							
		}
				
		return $items;		    	 		
	
	}
	

	
}

