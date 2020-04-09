<?php

function startup_full() {

// basic json config settings
$default_config = file_get_contents($_SERVER['DOCUMENT_ROOT'].'/app/config.json');
$custom_config = file_get_contents($_SERVER['DOCUMENT_ROOT'].'/config.json');

$merged_config = json_encode(
    array_replace_recursive(
    json_decode($default_config, true),
    json_decode($custom_config, true)
));

$config = json_decode($merged_config);

// require and register Mustache
require $_SERVER['DOCUMENT_ROOT'].'/app/vendor/Mustache/Autoloader.php';
Mustache_Autoloader::register();
$options =  array('extension' => '.ms');
$theme = $config->settings->theme;
$mustache = new Mustache_Engine(array(
    'partials_loader' => new Mustache_Loader_FilesystemLoader($_SERVER['DOCUMENT_ROOT'] . '/themes/'.$theme.'/_partials', $options),
));

//require markdown and use Markdown
require $_SERVER['DOCUMENT_ROOT'].'/app/vendor/markdown/Markdown.inc.php';
$markdown = new Michelf\Markdown;

//require Frontmatter
require $_SERVER['DOCUMENT_ROOT'].'/app/vendor/frontmatter/Frontmatter.php';
$frontmatter = new FrontMatter;

//require /app/lib
spl_autoload_register(function ($class) {
	require_once $_SERVER['DOCUMENT_ROOT'] . '/app/lib/' . $class . '.php';
});

// setup base objects work work from
$tree = new ContentTreeHandler;
$content = new ContentFileHandler;
$template = new TemplateFileHandler($config);
$view = new ViewHandler($config, $tree, array());
$data = new TagDataHandler($config, $tree, array(
    'helpers' => array(
        'frontmatter' => new FrontMatter,
        'markdown' => new Michelf\Markdown,
    ),
    // [T] might need to move lambdas into a Class as they get longer
    'lambdas' => array(
        'f_uppercase' => static function ($text, $render) {
            return strtoupper($render($text));
        },
        'f_lowercase' => static function ($text, $render) {
            return strtolower($render($text));
        },
        'f_capitalize' => static function ($text, $render) {
            return ucfirst($render($text));
        },
        'f_markdown' => function ($text, $render) {
            $markdown = new Michelf\Markdown;
            return $markdown->transform($render($text));
        },
        'f_date_RFC339' => function ($text, $render) {
            $utility = new UtilityHandler;
            $timeStamp = $utility->parseDate($text);
            return date(DATE_RFC3339, $timeStamp);
        }
    )
));

// [T] this might need to become a router of sorts
// Get the request
$request = $_SERVER['REQUEST_URI'];

$uriArr = parse_url($request);
$pathArr = explode('/', trim($uriArr['path'], '/'));
$pathArrLength = count($pathArr);

// Get what content & template file should be
$content->get($request);
$template->get($request);

// check for feed
if($view->validate('feed', $request)) {

    // let's create our big bulky data object without fm to pass to mustache
    $data->create('feed', array(
        'config_obj' => $config,
        'path_arr' => $pathArr,
        'tree_obj' => $tree
    ));
    echo $mustache->render($template->fileContentsRaw, $data->fields);

}

// otherwise check for archive
elseif($view->validate('archive', $request)) {

    // let's create our big bulky data object without fm to pass to mustache
    $data->create('archive', array(
        'config_obj' => $config,
        'path_arr' => $pathArr,
        'tree_obj' => $tree
    ));

    echo $mustache->render($template->fileContentsRaw, $data->fields);

}

// otherwise check valid view, verify content file exists for posts and pages
elseif ($view->validate('postpage', $request) && $content->fileExists) {
    $fm = $frontmatter->process($content->filePath);
    $fm['content'] = $markdown->transform($fm['content']);

    // let's create our big bulky data object to pass to mustache
    $data->create($fm);
    $data->fields['content'] = $mustache->render($data->fields['content'], $data->fields);

    echo $mustache->render($template->fileContentsRaw, $data->fields);

}

// throw 404 if no content file found, and no valid view
else {
    http_response_code(404);
    $content->get('/404');
    $template->get('/404');

    $fm = $frontmatter->process($content->filePath);
    $fm['content'] = $markdown->transform($fm['content']);

    $data->create($fm);

    echo $mustache->render($template->fileContentsRaw, $data->fields);
}

}
