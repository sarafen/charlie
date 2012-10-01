<?php

//Define New Loopers

//Blog LOOPER
$page->add_looper(
	'blog_looper',
	array(
		'loop_type' => 'default',
		'content_type' => 'blog',
		'date_format' => 'F jS Y'
	)
);