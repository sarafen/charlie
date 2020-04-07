<?php

class ContentTreeHandler {

    private $contentDir;
    public $contentTree;

    public function __construct() {
        $this->contentDir = $_SERVER['DOCUMENT_ROOT'].'/content/';

        $types = array_slice(scandir($this->contentDir), 2);

        foreach($types as $key => $val) {

            if (is_dir($this->contentDir.'/'.$val)) {

                $branch = preg_grep('/^([^.])/', array_slice(scandir($this->contentDir.'/'.$val), 2));

                $branchPath = $this->contentDir.'/'.$val;
                foreach($branch as $index => $item) {
                    if(is_dir($branchPath. '/' . $item)) {
                        unset($branch[$index]);
                    }
                }

                $tree[$val] = $branch;
          }

        }

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
