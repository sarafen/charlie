<?php

//Define New Loopers

//Blog LOOPER
$page_data->add_looper(
	'blog_looper',
	array(
		'loop_type' => 'default',
		'content_type' => 'blog',
		'date_format' => 'F j, Y'
	)
);