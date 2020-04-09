<?php

# let people know if they are running an unsupported version of PHP
if(phpversion() < 7.2) {

  die('<h1>Charlie requires PHP/7.2 or higher.<br>You are currently running PHP/'.phpversion().'.</h1><p>You should contact your host to see if they can upgrade your version of PHP.</p>');

} else {

  # set a more reliable DOCUMENT_ROOT for shared hosting environments
  define('DOCUMENT_ROOT', dirname(__FILE__));
  require_once DOCUMENT_ROOT.'/app/startup.php';
  startup_full();

}
