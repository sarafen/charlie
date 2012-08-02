<?php

/* index.tpl.php */
class __TwigTemplate_bf655a8eec70d98ec689c027614d4cd6 extends Twig_Template
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
        echo "<?php get_header(); ?>

";
        // line 3
        $this->env->loadTemplate("header.tpl.php")->display($context);
        // line 4
        echo "
<body id=\"front\">


<h1><a href=\"/\" id=\"logo\">Stephen Creates</a></h1>

<?php get_partial('menu'); ?>

";
        // line 12
        if (isset($context["data"])) { $_data_ = $context["data"]; } else { $_data_ = null; }
        echo twig_escape_filter($this->env, $this->getAttribute($_data_, "title"), "html", null, true);
        echo "

";
        // line 15
        if (isset($context["data"])) { $_data_ = $context["data"]; } else { $_data_ = null; }
        echo $this->getAttribute($_data_, "content");
        echo "
";
        // line 17
        echo "<section id=\"news\">
\t
</section>

<section id=\"recent-work\">
\t<a href=\"#\" class=\"img one\">dezby &rarr;</a>
\t<a href=\"#\" class=\"img two\">ambalamb &rarr;</a>
\t<a href=\"#\" class=\"img three\">Adulting Blog &rarr;</a>
</section>

<footer role=\"contentinfo\">
<p>Created by Stephen Lovell</p>

<!-- <p>&copy; 2012</p> -->

</footer>

<?php news(); ?>

<script src=\"http://ajax.googleapis.com/ajax/libs/jquery/1.7/jquery.min.js\"></script> 
<script src=\"<?php get_theme_dir(); ?>/js/fixie.min.js\"></script> 
<script src=\"<?php get_theme_dir(); ?>/js/moment.min.js\"></script> 
<script src=\"<?php get_theme_dir(); ?>/js/jq.tweet.min.js\"></script> 
<script src=\"<?php get_theme_dir(); ?>/js/bundle.js\"></script> 
</body>
</html>";
    }

    public function getTemplateName()
    {
        return "index.tpl.php";
    }

    public function isTraitable()
    {
        return false;
    }

    public function getDebugInfo()
    {
        return array (  44 => 17,  39 => 15,  33 => 12,  23 => 4,  21 => 3,  17 => 1,);
    }
}
