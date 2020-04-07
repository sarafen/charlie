<?php

class ViewHandler {

    // private $params;
    // public $request;
    private $config_obj;
    private $tree_obj;


    public function __construct($config_obj,$tree_obj,$options_arr) {

        $this->config_obj = $config_obj;
        $this->tree_obj = $tree_obj;

        // process helper frontmatter & markdown, etc. objects here

    }

    public function render($template_obj, $data_obj) {

        $template = $template_obj->fileContentsRaw;
        $data = $data_obj->fields;

        return $mustache->render($template, $data);
    }

    public function validate($view_type, $request) {

        switch ($view_type) {
            case 'archive' :
                return $this->validateArchive($request);
                break;
            case ('feed') :
                return $this->validateFeed($request);
                break;
            case 'postpage' :
                return $this->validatePostPage($request);
                break;
            case 'post' :
                return $this->validatePost($request);
                break;
            case 'page' :
                return $this->validatePage($request);
                break;
            default:
                return false;
                break;
        }

    }

    private function validateArchive($request) {
        $tree = $this->tree_obj;
        $config = $this->config_obj;

        $uriArr = parse_url($request);
        $pathArr = explode('/', trim($uriArr['path'], '/'));
        $pathArrLength = count($pathArr);

        if (
            !array_key_exists(3, $pathArr) &&
            array_key_exists(2, $pathArr) &&
            $pathArr[2] != 0 &&
            $pathArr[1] == 'pg' &&
            array_key_exists($pathArr[0], $tree->contentTree) &&
            $config->settings->archives->{$pathArr[0]}->enabled
        ) {

            $limit = $config->settings->archives->{$pathArr[0]}->limit;
            $page_count = ceil(count($tree->query($pathArr[0])) / $limit);

            if($pathArr[2] <= $page_count) {
                return true;
            }
        }

    }

    private function validateFeed($request) {
        $tree = $this->tree_obj;
        $config = $this->config_obj;

        $uriArr = parse_url($request);
        $pathArr = explode('/', trim($uriArr['path'], '/'));
        $pathArrLength = count($pathArr);

        if (
            !array_key_exists(3, $pathArr) &&
            array_key_exists(1, $pathArr)
        ) {

            if (
                $pathArr[1] == 'feed' &&
                array_key_exists($pathArr[0], $tree->contentTree) &&
                $config->settings->feeds->{$pathArr[0]}->enabled
            ) {
                if ($pathArr[2] == 'rss' || $pathArr[2] == 'json') {

                    return true;

                }
            }
        }
    }

    private function validatePostPage($request) {
        $uriArr = parse_url($request);
        $pathArr = explode('/', trim($uriArr['path'], '/'));
        $pathArrLength = count($pathArr);

        if ($pathArr[0] != '_blocks' &&
            $pathArr[0] != 'imgs' &&
            $pathArr[0] != 'files') {

                return true;
        }

    }

}
