<?php

class TemplateFileHandler {

    private $themeDir;

    public $fileExists;
	public $fileName;
    public $fileExtension;
    public $filePath;
    //public $fileRelativePath;
    public $fileContentsRaw;
    public $contentParent;
    //public $contentGrandParent;
    public $contentType;

    public function __construct($config_obj) {
        $theme = $config_obj->settings->theme;

        $this->themeDir = $_SERVER['DOCUMENT_ROOT'].'/themes/'.$theme.'/';
        $this->fileExtension = '.ms';
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

                if (array_key_exists(2, $pathArr) && $pathArr[1] == 'pg') {
                    return 'archive';

                }
                elseif(array_key_exists(2, $pathArr) && $pathArr[1] == 'feed') {

                    switch ($pathArr[2]) {
                        case 'rss' :
                            return 'feedRSS';
                            break;

                        case 'json' :
                            return 'feedJSON';
                            break;
                    }

                } else {

                    return $pathArr[$pathArrLength - 1];

            }
        }

	}

    public function contentType($request) {

        $uriArr = parse_url($request);

        $pathArr = explode('/', trim($uriArr['path'], '/'));
        $pathArrLength = count($pathArr);

        if (array_key_exists(1, $pathArr) && $pathArr[1] == 'pg') {
            return 'archive';

        }
        elseif(array_key_exists(1, $pathArr) && $pathArr[1] == 'feed') {
            return 'feed';
        }
        elseif ($pathArrLength == 1 ) {
            return 'page';

        } else {
            return 'post';
        }

	}

    public function contentParent($request) {

        $uriArr = parse_url($request);

        $pathArr = explode('/', trim($uriArr['path'], '/'));
        $pathArrLength = count($pathArr);

        if ($pathArrLength >= 3 ) {
            return $pathArr[$pathArrLength-3];
        }

        elseif ($pathArrLength >= 2 ) {
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

	public function cascade($type) {

        switch ($type) {
            case 'archive' :
                $parentDir = '';

                if (file_exists($this->themeDir.$type.'-'.$this->contentParent.$this->fileExtension)) {
                    return $this->themeDir.$type.'-'.$this->contentParent.$this->fileExtension;
                } elseif(file_exists($this->themeDir.$parentDir.$this->fileName.$this->fileExtension)) {
                    return $this->themeDir.$parentDir.$this->fileName.$this->fileExtension;
                } else {
                    return $_SERVER['DOCUMENT_ROOT'].'/app/lib/ms_templates/'.$this->fileName.$this->fileExtension;
                }
                break;

            case 'feed' :

                if (file_exists($this->themeDir.$this->fileName.'-'.$this->contentParent.$this->fileExtension)) {
                    return $this->themeDir.$this->fileName.'-'.$this->contentParent.$this->fileExtension;
                } elseif(file_exists($this->themeDir.'/'.$this->fileName.$this->fileExtension)) {
                    return $this->themeDir.'/'.$this->fileName.$this->fileExtension;
                } else {
                    return $_SERVER['DOCUMENT_ROOT'].'/app/lib/ms_templates/'.$this->fileName.$this->fileExtension;
                }
                break;

            case 'page' :
                $parentDir = 'pages/';
                break;

            case 'post' :
                $parentDir = $this->contentParent.'/';
                break;

        }

        if (file_exists($this->themeDir.$parentDir.$this->fileName.$this->fileExtension)) {

            return $this->themeDir.$parentDir.$this->fileName.$this->fileExtension;

        } elseif (file_exists($this->themeDir.$type.'-'.$this->contentParent.$this->fileExtension)) {

            return $this->themeDir.$type.'-'.$this->contentParent.$this->fileExtension;

        } elseif (file_exists($this->themeDir.$type.$this->fileExtension)) {

            return $this->themeDir.$type.$this->fileExtension;

        } else {

            return $this->themeDir.'index'.$this->fileExtension;

        }

	}

    public function exists($file) {

    	if (file_exists($file)) {

    		return true;

    	} else {
            return false;
        }

    }
 }
