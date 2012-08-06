<?php

// Sets up the Page Object 

class Data extends Charlie_Data {  


 //Used for tweet.js for custom caching
    public function news_cache() {

		include_once('./app/inc/cache_flow.php');
		
		cache_money(
			'https://api.twitter.com/1/statuses/user_timeline.json?screen_name=stephencreates&count=40&page=1&include_entities=1&callback=?', //API src
			'./cache/twitter.js', //Cache file dir
			'1000', //Cache life in seconds
			'twitter',//Cache src format
			'off' //debug?
			);
	}


}