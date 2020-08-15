<?php

class RequestHandler {

    private $uriArr;

    public $path;
    public $pathArr;
    public $pathArrLength;

    // public $queryArr;
    // public $queryArrLength;

    public function __construct($request_uri) {
      $this->uriArr = parse_url($request_uri);

      $this->path = $this->buildPath($this->uriArr);
      $this->pathArr = $this->buildPathArr($this->path);
      $this->pathArrLength = count($this->pathArr);

      // $this->queryArr = $this->buildQueryArr($this->uriArr);
      // $this->queryArrLength = count($this->queryArr);
    }

    private function sanitizePath($path) {

      $path = htmlspecialchars(strval($path));

      // strip down the path to accept only [a-z A-Z 0-9 - _ /]
      if(!preg_match('/^[\/\w-]+$/',$path)) {

        $path = 'invalid';

      }

      return $path;
    }

    private function buildPath($uriArr) {

      $path = $uriArr['path'];

      $path = $this->sanitizePath($path);

      return $path;
    }

    private function buildPathArr($path) {

      $pathArr = explode('/', trim($path, '/'));

      return $pathArr;
    }

    // private function sanitizeQueryParam($uriArrParam) {
    //
    //   //do some regex stuff on an individual param to strip out things.
    //
    //   return $uriArrParam;
    //
    //
    // }
    //
    // private function buildQueryArr($uriArr) {
    //
    //   $queryRaw = $uriArr['query'];
    //
    //   $queryArr = explode('&', trim($queryRaw, '&')); //this is wrong, fix.
    //
    //   //walk through array and run $this->sanitizeQueryParam on each item
    //
    //   return $queryArr;
    //
    // }

}
