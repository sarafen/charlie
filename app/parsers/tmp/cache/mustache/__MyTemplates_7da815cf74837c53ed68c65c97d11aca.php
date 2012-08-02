<?php

class __MyTemplates_7da815cf74837c53ed68c65c97d11aca extends Mustache_Template
{
    public function renderInternal(Mustache_Context $context, $indent = '', $escape = false)
    {
        $buffer = '';

        $buffer .= $indent . '<!DOCTYPE html> ';
        $buffer .= "\n";
        $buffer .= $indent . '<html lang="en">';
        $buffer .= "\n";
        $buffer .= $indent . '<head>';
        $buffer .= "\n";
        $buffer .= "\n";
        $buffer .= $indent . '<meta charset="utf-8" />';
        $buffer .= "\n";
        $buffer .= $indent . '<meta name=\'description\' content=\'\' />';
        $buffer .= "\n";
        $buffer .= $indent . '<meta name=\'keywords\' content=\'\' />';
        $buffer .= "\n";
        $buffer .= $indent . '<meta name="author" content="Stephen Lovell" />';
        $buffer .= "\n";
        $buffer .= $indent . '<meta name="viewport" content="width=device-width, initial-scale=1.0, minimum-scale=1.0" />';
        $buffer .= "\n";
        $buffer .= "\n";
        $buffer .= $indent . '<title>stephen creates</title>';
        $buffer .= "\n";
        $buffer .= "\n";
        $buffer .= $indent . '<link rel="shortcut icon" href="imgs/favicon.ico" />';
        $buffer .= "\n";
        $buffer .= "\n";
        $buffer .= $indent . '<!--[if ! lte IE 6]><!-->';
        $buffer .= "\n";
        $buffer .= $indent . '<!-- <link rel="stylesheet" media="screen, projection" href="<?php get_theme_dir(); ?>/css/style.css" /> -->';
        $buffer .= "\n";
        $buffer .= $indent . '<link rel="stylesheet" media="screen, projection" href="';
        $value = $context->find('theme_dir');
        if (!is_string($value) && is_callable($value)) {
            $value = $this->mustache
                ->loadLambda((string) call_user_func($value))
                ->renderInternal($context, $indent);
        }
        $buffer .= call_user_func($this->mustache->getEscape(), $value);
        $buffer .= '/css/style.css" />';
        $buffer .= "\n";
        $buffer .= "\n";
        $buffer .= "\n";
        $buffer .= $indent . '<!--<![endif]-->';
        $buffer .= "\n";
        $buffer .= "\n";
        $buffer .= $indent . '<!--[if lte IE 6]>';
        $buffer .= "\n";
        $buffer .= $indent . '<link rel="stylesheet" media="screen, projection" href="http://universal-ie6-css.googlecode.com/files/ie6.1.1b.css">';
        $buffer .= "\n";
        $buffer .= $indent . '<![endif]-->';
        $buffer .= "\n";
        $buffer .= "\n";
        $buffer .= $indent . '<!-- enable HTML5 elements in IE7+8 -->';
        $buffer .= "\n";
        $buffer .= $indent . '<!--[if lt IE 9]>';
        $buffer .= "\n";
        $buffer .= $indent . '<script src="http://html5shim.googlecode.com/svn/trunk/html5.js"></script>';
        $buffer .= "\n";
        $buffer .= $indent . '<![endif]-->';
        $buffer .= "\n";
        $buffer .= "\n";
        $buffer .= $indent . '<script type="text/javascript" src="http://use.typekit.com/mko1ywr.js"></script>';
        $buffer .= "\n";
        $buffer .= $indent . '<script type="text/javascript">try{Typekit.load();}catch(e){}</script>';
        $buffer .= "\n";
        $buffer .= $indent . '	';
        $buffer .= "\n";
        $buffer .= $indent . '</head>';

        if ($escape) {
            return call_user_func($this->mustache->getEscape(), $buffer);
        } else {
            return $buffer;
        }
    }

}