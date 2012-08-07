/*
 * Script Bundle
 *
 * Copyright (c) 2011 Stephen Lovell (unless noted otherwise)
 *
 */

$(document).ready(function(){

//Tweet.js Settings


	$("#news").tweet({
		username: 'stephencreates',
		count: 1,
		fetch: 40,
		filter: function(t){ return /(\B#sc|\bword)\b/.test(t.tweet_raw_text); },
		loading_text: "Loading...",
		retweets: false,
		template: function(o) {
			return $.tweet.t('<article class="reveal"><p>{tweet_text_fancy_dehash}</span></p></article>', 
			$.extend({	         				
				tweet_year: moment(o.tweet_time).format("YYYY"),
				tweet_month: moment(o.tweet_time).format("MMM"),
				tweet_date: moment(o.tweet_time).format("DD"),
				tweet_day: moment(o.tweet_time).format("ddd"),
				tweet_hour: moment(o.tweet_time).format("H"),
				tweet_minutes: moment(o.tweet_time).format("mm"),
				tweet_seconds: moment(o.tweet_time).format("ss"),
				tweet_time_ending: moment(o.tweet_time).format("A"),
				tweet_human_time: moment(o.tweet_time).format("dddd, MMMM Do YYYY, h:mm:ss A"),
					
				//Remove hashtags and wrapped anchors completely.
				tweet_text_fancy_dehash: $([o.tweet_text]).dehash().makeHeart().capAwesome().capEpic()[0]
				
			}, o));
		}  
	});	
	
});