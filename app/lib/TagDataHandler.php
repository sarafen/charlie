<?php

class TagDataHandler {

    public $helpers;

    private $globalFields;
    private $globalDynamicFields;
    public $globalLoopers;
    public $globalBlocks;
    public $globalLambdas;
    private $contentFields;

    public $fields;


    public function __construct($config_obj,$tree_obj,$options_arr) {

        $this->helpers = $options_arr['helpers'];

        $this->globalFields = $this->extractGlobalFields($config_obj);
        $this->globalDynamicFields = $this->appendDynamicGlobalFields($config_obj);
        $this->globalLoopers = $this->generateLoopsData($config_obj,$tree_obj);
        $this->globalBlocks = $this->generateBlocksData($tree_obj);
        $this->globalLambdas = $options_arr['lambdas'];

    }

    // public function getFields() {
    //     return $this->fields;
    // }

    public function create($opj = null, $params = null) {

        $frontmatter_obj = $opj;
        $this->contentFields = $this->extractContentFields($frontmatter_obj);
        $this->fields = $this->constructData();

        switch ($opj) {
            case 'archive' :
                $this->buildArchiveLoop($params);
                break;

            case 'feed' :
                $this->buildFeedLoop($params);
                break;
            default:
                //echo 'default';
                break;
        }

    }

    private function extractGlobalFields($obj) {

        $array = (array) $obj->globals;

        return $array;
    }

    private function appendDynamicGlobalFields($obj) {

        $settings = $obj->settings;

        $fields = [];

        $fields['current_year'] = date("Y");
		$fields['theme_dir'] = '/themes/'.$settings->theme;

        return $fields;

    }

    // private function extractGlobalLoopers($obj) {
    //
    //     // dummy items for now
    //     $items = array('items' => array());
    //     $items['item'][0] = ['title' => 'hello world', 'content' => 'content for earth'];
    //     $items['item'][1] = ['title' => 'hello mars', 'content' => 'content for mars'];
    //
    //     foreach ($obj->loopers as $key => $val) {
    //
	// 	    $data['looper__'.$key] = $items;
    //
	//     }
    //
    //     return $data;
    // }

    private function generateLoopsData($obj, $tree) {

        foreach ($obj->loopers as $key => $val) {

            $params = $obj->loopers->{$key};

            switch ($params->loop_type) {
                case 'default' :
                    $data['looper'][$key] = $this->buildDefaultLoop($params,$tree);
                    break;
                case 'feed' :
                    $data['looper'][$key] = $this->buildFeedLoop($params,$tree);
                    break;
            }

            //reorder array by sort_by

            // $sorted = $data['looper'][$key]['item']
            //
            // array_multisort(array_column($sorted, 'order'), SORT_DESC, $sorted);
            //
            // $data['looper'][$key] = $sorted;
            //
            // var_dump($data['looper'][$key]['item']);

            // function cmp($a, $b) {
            //     return count($a['order'], $b['order']);
            // }
            //
            // usort($data['looper'][$key]['item'], "cmp");

	    }

        return $data;
    }

    public function buildDefaultLoop($params,$tree) {
        $frontmatter = $this->helpers['frontmatter'];
        $markdown = $this->helpers['markdown'];
        $items = array();
        $items['item'] = array();

        $i = 0;
        foreach ($tree->query($params->content_filter) as $key => $val) {
            $name = basename($val, ".md");

            $fm = $frontmatter->process($_SERVER['DOCUMENT_ROOT'].'/content/'.$params->content_filter.'/'.$val);

            //var_dump($fm);
            //echo 'base_name: '.$name.'<br />';

            foreach ($fm as $key => $val) {

                $fields[$key] = $val;

            }

            //massage or append to any fields after assignment.
            $fields['content'] = $markdown->transform($fields['content']);
            $fields['link'] = '/'.$params->content_filter.'/'.$name;

            //$fields['order'] = 0;

            //$items['item'][$i] = ['file_name' => $val];
            $items['item'][$i] = $fields;

            $i++;
            if($i == $params->limit) break;
        }

        // sort items by $params->sort_by
        if(isset($params->sort_by)) {

            $sort_by = $params->sort_by;

            if(isset($params->sort_order)) {

                $sort_order = $params->sort_order;

                switch ($sort_order) {
                    case 'ASC' :
                        array_multisort(array_column($items['item'], $sort_by), SORT_ASC, $items['item']);
                        break;

                    case 'DESC' :
                        array_multisort(array_column($items['item'], $sort_by), SORT_DESC, $items['item']);
                        break;
                }

            } else {

              array_multisort(array_column($items['item'], $sort_by), SORT_ASC, $items['item']);

            }
        }

        return $items;
    }

    public function buildFeedLoop($params) {

        $frontmatter = $this->helpers['frontmatter'];
        $config = $params['config_obj'];
        $pathArr = $params['path_arr'];
        $tree = $params['tree_obj'];


        $items = array();
        $items['post']['feed']['item'] = array();
        $i = 0;
        foreach ($tree->query($pathArr[0]) as $key => $val) {


            $name = basename($val, ".md");
            $fm = $frontmatter->process($_SERVER['DOCUMENT_ROOT'].'/content/'.$pathArr[0].'/'.$val);

            foreach ($fm as $key => $val) {

                $fields[$key] = $val;

            }

            list($month, $day, $year) = explode('/', $fields['date']);
            $timeStamp = mktime(0, 0, 0, $month, $day, $year);

            $fields['date'] = date(DATE_RFC3339, $timeStamp);

            $fields['link'] = '/'.$pathArr[0].'/'.$name;

            $items['post']['feed']['item'][$i] = $fields;

            $i++;

        }
        $items['post']['type'] = $pathArr[0];


        if(isset($config->settings->archives->{$pathArr[0]}->sort_by)) {

            $sort_by = $config->settings->archives->{$pathArr[0]}->sort_by;

            if(isset($config->settings->archives->{$pathArr[0]}->sort_order)) {

                $sort_order = $config->settings->archives->{$pathArr[0]}->sort_order;

                switch ($sort_order) {
                    case 'ASC' :
                        array_multisort(array_column($items['post']['feed']['item'], 'date'), SORT_ASC, $items['post']['feed']['item']);
                        break;

                    case 'DESC' :
                        array_multisort(array_column($items['post']['feed']['item'], 'date'), SORT_DESC, $items['post']['feed']['item']);
                        break;
                }

            } else {

              array_multisort(array_column($items['post']['feed']['item'], 'date'), SORT_DESC, $items['post']['feed']['item']);

            }
        } else {

          array_multisort(array_column($items['post']['feed']['item'], 'date'), SORT_DESC, $items['post']['feed']['item']);
        }

        $this->fields = array_merge($this->fields, $items);

        // this loop would generate a valid RSS feed in atom format, for now its just a clone of the default
        // $frontmatter = $this->helpers['frontmatter'];
        // $items = array();
        //
        // $i = 0;
        // foreach ($tree->query($params->content_filter) as $key => $val) {
        //
        //     $frontmatter->process($_SERVER['DOCUMENT_ROOT'].'/content/blog/hello-mars.md');
        //
        //     foreach ($frontmatter->data as $key => $val) {
        //
        //         $fields[$key] = $val;
        //     }
        //
        //     $items['item'][$i] = $fields;
        //
        //     $i++;
        //     if($i == $params->limit) break;
        // }
        //
        // return $items;
    }

    public function buildArchiveLoop($params) {

        $frontmatter = $this->helpers['frontmatter'];
        $config = $params['config_obj'];
        $pathArr = $params['path_arr'];
        $tree = $params['tree_obj'];

        $limit = $config->settings->archives->{$pathArr[0]}->limit;
        $offset = 0;
        $page_count = ceil(count($tree->query($pathArr[0])) / $limit);

        if ($pathArr[2] > 1 ) {
            $offset = $limit * ($pathArr[2] - 1);
        }

        $items = array();
        $items['post']['archive']['item'] = array();
        $i = 0;
        foreach ($tree->query($pathArr[0]) as $key => $val) {

            if ($key < $offset) continue;

            $name = basename($val, ".md");
            $fm = $frontmatter->process($_SERVER['DOCUMENT_ROOT'].'/content/'.$pathArr[0].'/'.$val);

            foreach ($fm as $key => $val) {

                $fields[$key] = $val;

            }

            $fields['link'] = '/'.$pathArr[0].'/'.$name;

            $items['post']['archive']['item'][$i] = $fields;


            $i++;

            if($i == $limit) break;

        }

        $items['post']['type'] = $pathArr[0];

        if ($page_count > 1) {
            $i = 0;
            while ($i < $page_count) {
                $num = $i + 1;

                if ($num != $pathArr[2]) {
                    $items['post']['pagination']['item'][$i]['link'] = '/'.$pathArr[0].'/pg/'.$num;
                }
                $items['post']['pagination']['item'][$i]['num'] = $num;

                $i++;
            }
        }

        if(isset($config->settings->archives->{$pathArr[0]}->sort_by)) {

            $sort_by = $config->settings->archives->{$pathArr[0]}->sort_by;

            if(isset($config->settings->archives->{$pathArr[0]}->sort_order)) {

                $sort_order = $config->settings->archives->{$pathArr[0]}->sort_order;

                switch ($sort_order) {
                    case 'ASC' :
                        array_multisort(array_column($items['post']['archive']['item'], 'date'), SORT_ASC, $items['post']['archive']['item']);
                        break;

                    case 'DESC' :
                        array_multisort(array_column($items['post']['archive']['item'], 'date'), SORT_DESC, $items['post']['archive']['item']);
                        break;
                }

            } else {

              array_multisort(array_column($items['post']['archive']['item'], 'date'), SORT_DESC, $items['post']['archive']['item']);

            }
        } else {

            array_multisort(array_column($items['post']['archive']['item'], 'date'), SORT_DESC, $items['post']['archive']['item']);

        }


        $this->fields = array_merge($this->fields, $items);

        //return $items;

    }

    private function extractContentFields($obj) {

        $array = (array) $obj;
        return $array;
    }

    private function generateBlocksData($tree) {

        $items = [];
        foreach ($tree->query('_blocks') as $key => $val) {

            $markdown = $this->helpers['markdown'];

            $name = basename($val, '.md');
            $content = file_get_contents($_SERVER['DOCUMENT_ROOT'].'/content/_blocks/'.$val);

            $items['block'][$name] = $markdown->transform($content);
        }

        return $items;
    }

    private function constructData() {

        //assemble all the objects together into one massively joined array, structured appropriately.
        $data = array_merge($this->globalFields, $this->globalDynamicFields, $this->globalLoopers, $this->globalBlocks, $this->contentFields,$this->globalLambdas);

        return $data;
    }

    // public function lambdas() {
    //
    //     $lambdaArr = [
    //         'f_uppercase' => static function ($text, $render) {
    //             return strtoupper($render($text));
    //         },
    //         'f_lowercase' => static function ($text, $render) {
    //             return strtolower($render($text));
    //         },
    //         'f_markdown' => function ($text, $render) {
    //             $markdown = $this->helpers['markdown'];
    //             return $markdown->transform($render($text));
    //         }
    //     ];
    //
    //
    //     return $lambdaArr;
    //
    // }

}
