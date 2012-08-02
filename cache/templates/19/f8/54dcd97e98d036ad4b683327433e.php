<?php

/* header.tpl.php */
class __TwigTemplate_19f854dcd97e98d036ad4b683327433e extends Twig_Template
{
    public function __construct(Twig_Environment $env)
    {
        parent::__construct($env);

        $this->parent = false;

        $this->blocks = array(
        );
    }

    protected function doDisplay(array $context, array $blocks = array())
    {
        // line 1
        echo "<!DOCTYPE html> 
<html lang=\"en\">
<head>

<meta charset=\"utf-8\" />
<meta name='description' content='' />
<meta name='keywords' content='' />
<meta name=\"author\" content=\"Stephen Lovell\" />
<meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0, minimum-scale=1.0\" />

<title>stephen creates</title>

<link rel=\"shortcut icon\" href=\"imgs/favicon.ico\" />

<!--[if ! lte IE 6]><!-->
<link rel=\"stylesheet\" media=\"screen, projection\" href=\"<?php get_theme_dir(); ?>/css/style.css\" />
<link rel=\"stylesheet\" media=\"screen, projection\" href=\"";
        // line 17
        if (isset($context["data"])) { $_data_ = $context["data"]; } else { $_data_ = null; }
        echo twig_escape_filter($this->env, $this->getAttribute($_data_, "theme_dir"), "html", null, true);
        echo "/css/style.css\" />
<!-- <link rel=\"stylesheet\" media=\"screen, projection\" href=\"http://charlie.dev/themes/tesla/css/style.css\" /> -->


<!--<![endif]-->

<!--[if lte IE 6]>
<link rel=\"stylesheet\" media=\"screen, projection\" href=\"http://universal-ie6-css.googlecode.com/files/ie6.1.1b.css\">
<![endif]-->

<!-- enable HTML5 elements in IE7+8 -->
<!--[if lt IE 9]>
<script src=\"http://html5shim.googlecode.com/svn/trunk/html5.js\"></script>
<![endif]-->

<script type=\"text/javascript\" src=\"http://use.typekit.com/mko1ywr.js\"></script>
<script type=\"text/javascript\">try{Typekit.load();}catch(e){}</script>
\t
</head>";
    }

    public function getTemplateName()
    {
        return "header.tpl.php";
    }

    public function isTraitable()
    {
        return false;
    }

    public function getDebugInfo()
    {
        return array (  35 => 17,  17 => 1,);
    }
}
