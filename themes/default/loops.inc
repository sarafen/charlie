<?php

//Define New Loopers

//Blog LOOPER
/*
$page->blog_looper = looper(
	$feed_type = 'default',
	$content_type = 'blog',
	$date_format = 'F jS Y'
);
*/

$page->add_looper(

	'blog_looper',
	'default',
	'blog',
	'F jS Y'
);
