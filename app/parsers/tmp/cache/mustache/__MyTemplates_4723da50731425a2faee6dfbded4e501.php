<?php

class __MyTemplates_4723da50731425a2faee6dfbded4e501 extends Mustache_Template
{
    public function renderInternal(Mustache_Context $context, $indent = '', $escape = false)
    {
        $buffer = '';

        $buffer .= "\n";
        $value = $context->find('>header');
        if (!is_string($value) && is_callable($value)) {
            $value = $this->mustache
                ->loadLambda((string) call_user_func($value))
                ->renderInternal($context, $indent);
        }
        $buffer .= $indent . $value;
        $buffer .= "\n";
        $buffer .= "\n";
        $buffer .= "\n";
        $buffer .= $indent . '<body id="page">';
        $buffer .= "\n";
        $buffer .= "\n";
        $buffer .= "\n";
        $buffer .= $indent . '<h1><a href="/" id="logo">Stephen Creates</a></h1>';
        $buffer .= "\n";
        $buffer .= "\n";
        if ($partial = $this->mustache->loadPartial('menu')) {
            $buffer .= $partial->renderInternal($context, '');
        }
        $buffer .= $indent . ' ';
        $buffer .= "\n";
        $buffer .= $indent . '<section id="main-content">';
        $buffer .= "\n";
        $buffer .= $indent . '	';
        $buffer .= "\n";
        $buffer .= $indent . '	';
        $buffer .= "\n";
        $buffer .= $indent . '	';
        $value = $context->find('content');
        if (!is_string($value) && is_callable($value)) {
            $value = $this->mustache
                ->loadLambda((string) call_user_func($value))
                ->renderInternal($context, $indent);
        }
        $buffer .= $value;
        $buffer .= "\n";
        $buffer .= $indent . '	';
        $buffer .= "\n";
        $buffer .= $indent . '	';
        $buffer .= "\n";
        $buffer .= $indent . '</section>';
        $buffer .= "\n";
        $buffer .= "\n";
        $buffer .= "\n";
        $buffer .= "\n";
        $buffer .= "\n";
        $buffer .= "\n";
        $buffer .= "\n";
        $buffer .= "\n";
        $buffer .= $indent . '<footer role="contentinfo">';
        $buffer .= "\n";
        $buffer .= $indent . '<p>Created by Stephen Lovell</p>';
        $buffer .= "\n";
        $buffer .= "\n";
        $buffer .= $indent . '<!-- <p>&copy; 2012</p> -->';
        $buffer .= "\n";
        $buffer .= "\n";
        $buffer .= $indent . '</footer>';
        $buffer .= "\n";
        $buffer .= "\n";
        $buffer .= "\n";
        $buffer .= $indent . '<script src="http://ajax.googleapis.com/ajax/libs/jquery/1.7/jquery.min.js"></script> ';
        $buffer .= "\n";
        $buffer .= $indent . '<script src="<?php get_theme_dir(); ?>/js/fixie.min.js"></script> ';
        $buffer .= "\n";
        $buffer .= $indent . '<script src="<?php get_theme_dir(); ?>/js/bundle.js"></script> ';
        $buffer .= "\n";
        $buffer .= $indent . '</body>';
        $buffer .= "\n";
        $buffer .= $indent . '</html>';

        if ($escape) {
            return call_user_func($this->mustache->getEscape(), $buffer);
        } else {
            return $buffer;
        }
    }

}