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
                $tree[$val] = array_slice(scandir($this->contentDir.'/'.$val), 2);
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
