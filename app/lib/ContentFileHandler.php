<?php

class ContentFileHandler {

    private $contentDir;

    public $fileExists;
    public $fileName;
    public $fileExtension;
    public $filePath;
    //public $fileRelativePath;
    public $fileContentsRaw;
    public $contentParent;
    //public $contentGrandParent;
    public $contentType;

    public function __construct() {
        $this->contentDir = $_SERVER['DOCUMENT_ROOT'].'/content/';
        $this->fileExtension = '.md';
    }

    public function get($request) {

        $this->fileName = $this->fileName($request);

        $this->contentType = $this->contentType($request);
        $this->contentParent = $this->contentParent($request);

        $this->filePath = $this->cascade($this->contentType);
        //$this->fileRelativePath = '/content'.$request.$this->fileExtension;

        $this->fileExists = $this->exists($this->filePath);

        if ($this->fileExists) {

            $this->fileContentsRaw = $this->fileContentsRaw($this->filePath);
        }

    }

    public function fileName($request) {

        if ($request == '/' || '') {
            return 'index';
        } else {

            $uriArr = parse_url($request);

            $pathArr = explode('/', trim($uriArr['path'], '/'));
            $pathArrLength = count($pathArr);

            return $pathArr[$pathArrLength - 1];

        }

	}

    public function contentType($request) {

        $uriArr = parse_url($request);

        $pathArr = explode('/', trim($uriArr['path'], '/'));
        $pathArrLength = count($pathArr);

        if ($pathArrLength == 1 ) {
            return 'page';

        } else {
            return 'post';
        }

	}

    public function contentParent($request) {

        $uriArr = parse_url($request);

        $pathArr = explode('/', trim($uriArr['path'], '/'));
        $pathArrLength = count($pathArr);

        if ($pathArrLength >= 2 ) {
            return $pathArr[$pathArrLength-2];

        } else {
            return '';
        }

	}

    public function fileContentsRaw($file) {

        if (file_exists($file)) {

    		return file_get_contents($file);

    	} else {
            return false;
        }

	}

	private function cascade($type) {

        switch ($type) {
            case 'page' :
                return $this->contentDir.'pages/'.$this->fileName.$this->fileExtension;
                break;
            case 'post' :
                return $this->contentDir.$this->contentParent.'/'.$this->fileName.$this->fileExtension;
                break;
        }
	}

    // public function isFeed() {
    //     if($this->fileExists) {
    //         return false;
    //     } elseif($this->contentType = 'feed') {
    //         return true;
    //     }
    // }
    //
    // public function isArchive() {
    //     if($this->fileExists) {
    //         return false;
    //     } elseif($this->contentType = 'archive') {
    //         return true;
    //     }
    // }

    public function exists($file) {

    	if (file_exists($file)) {

    		return true;

    	} else {
        return false;
    }

    }
 }
