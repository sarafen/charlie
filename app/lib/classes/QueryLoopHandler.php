<?php

/*
 * !Needs a full rewrite and refactor
 *
 * Allows for the creation of dynamic Post loops similar to a light version
 * of the WordPress Loop. Loops are either standard or as a feed.
 */

class QueryLoopHandler {
			
	public function fetch($loop_type = 'default',$content_type,$date_format = 'l jS \of F Y h:i:s A',$limit='0') {
		
		//Build single POST
			
	    //Render LOOP
		$dir = $_SERVER['DOCUMENT_ROOT'].'/content/'.$content_type.'/';
		$files = scandir($dir);
		$files = array_reverse($files);
		$draft_files = preg_grep('!^__.!', $files);
		$files = array_diff($files, array('.', '..', '.DS_Store','imgs'),$draft_files);
			
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
	
	private function the_post($file,$path,$content_type,$date_format,$loop_type) {
				
		//Get frontmatter
		$post_fm = new FrontMatter($file);
		
		//Get Path
		$info = pathinfo($path);
		$path = basename($path,'.'.$info['extension']);
		$path = preg_replace("/^[0-9\\.\\s]+/", '', $path);
		$path = '/'.$content_type.'/'.$path.'/';
	
		//Get TITLE
	    
		//Get LINK
		//$link = DOMAIN.$path;
		$link = $path;
		
		//Assemble ID
		//$id = 'tag:'.DOMAIN.','.date('Y',filemtime($file)).':'.$path;
		
		//Get TEASER
	    //$teaser = There was a proper alt. here.
	    
				
		//$postObject = array();
		$postObject = $post_fm->data;
		
		
		//$postObject['title'] = $post_fm->fetch('title');
		//$postObject['teaser'] = $teaser;
		$postObject['link'] = $link;
		//$postObject['id'] = $id;
		
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

}

