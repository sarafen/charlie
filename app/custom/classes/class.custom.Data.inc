<?php


//include frontmatter
include_once('./app/charlie/parsers/frontmatter.php');


// Sets up the Page Object 
class Data extends Charlie_Data { 

	public $infinity;


	public function __construct() {
		
		parent::__construct();
		
		//Setup frontpage Object
		$fm = new FrontMatter('./content/pages/front.md');
		
		
		// Set Infinity
		$this->infinity = $fm->fetch('date');
		
			
		// Set Content
		$this->content = Markdown($fm->fetch('content'));
		
	}
	
	

	//Used for tweet.js for custom caching
    public function news_cache() {

		include_once('./app/custom/inc/cache_flow.php');
		
		cache_money(
			'https://api.twitter.com/1/statuses/user_timeline.json?screen_name=stephencreates&count=40&page=1&include_entities=1&callback=?', //API src
			'./cache/twitter.js', //Cache file dir
			'1000', //Cache life in seconds
			'twitter',//Cache src format
			'off' //debug?
			);
	}
				
	
	// Build Custom LOOPERS
	
	//Blog LOOPER
	public function blog_looper() {
		
		$items = $this->looper(
			$type = 'blog',
			$date_format = 'F jS Y'
		);
		
		return $items;
	
	}
	
	//Work LOOPER
	public function work_looper() {
		
		$items = $this->looper(
			$type = 'work',
			$date_format = 'F jS Y'
		);
		
		return $items;
	}


}