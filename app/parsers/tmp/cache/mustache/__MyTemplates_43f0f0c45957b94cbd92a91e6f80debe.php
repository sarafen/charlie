<?php

class __MyTemplates_43f0f0c45957b94cbd92a91e6f80debe extends Mustache_Template
{
    public function renderInternal(Mustache_Context $context, $indent = '', $escape = false)
    {
        $buffer = '';

        $buffer .= $indent . '<nav>';
        $buffer .= "\n";
        $buffer .= $indent . '<ul>';
        $buffer .= "\n";
        $buffer .= $indent . '	<li><a href="/work/" class="active">Work</a></li>';
        $buffer .= "\n";
        $buffer .= $indent . '	<li><a href="/info/">Info</a></li>';
        $buffer .= "\n";
        $buffer .= $indent . '	<li><a href="/blog/">Blog</a></li>';
        $buffer .= "\n";
        $buffer .= $indent . '	';
        $buffer .= "\n";
        $buffer .= $indent . '</ul>';
        $buffer .= "\n";
        $buffer .= $indent . '</nav>';

        if ($escape) {
            return call_user_func($this->mustache->getEscape(), $buffer);
        } else {
            return $buffer;
        }
    }

}