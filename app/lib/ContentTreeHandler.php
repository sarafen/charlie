<?php

class ContentTreeHandler {

    private $contentDir;
    public $contentTree;

    public function __construct() {
        $this->contentDir = $_SERVER['DOCUMENT_ROOT'].'/content/';

        $types = array_slice(scandir($this->contentDir), 2);

        // need to filter out .dot files here and any particular dirs

        foreach($types as $key => $val) {

            if (is_dir($this->contentDir.'/'.$val)) {
              
                $tree[$val] = preg_grep('/^([^.])/', array_slice(scandir($this->contentDir.'/'.$val), 2));

            }
        }


        // foreach($types as $type_key => $type_val) {
        //     foreach($tree[$val] as $file_key => $file_val) {
        //       if(is_dir($this->contentDir.'/'.$type_val.'/'.$file_val)){
        //           unset($tree[$val][$file_key]);
        //       }
        //
        //     }
        //
        // }








        $this->contentTree = $tree;

    }

    public function query($query) {
        if ($query) {
            return $this->contentTree[$query];
        } else {
            return $this->contentTree;
        }

    }

}
