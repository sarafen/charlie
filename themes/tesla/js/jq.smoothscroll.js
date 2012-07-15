/*!
 * jQuery Smooth Scroll Plugin v1.4.1
 *
 * Date: Tue Nov 15 14:24:14 2011 EST
 * Requires: jQuery v1.3+
 *
 * Copyright 2010, Karl Swedberg
 * Dual licensed under the MIT and GPL licenses (just like jQuery):
 * http://www.opensource.org/licenses/mit-license.php
 * http://www.gnu.org/licenses/gpl.html
 *
*/

(function(a){function g(a){return a.replace(/(:|\.)/g,"\\$1")}function f(a){return a.replace(/^\//,"").replace(/(index|default).[a-zA-Z]{3,4}$/,"").replace(/\/$/,"")}var b="1.4.1",c={exclude:[],excludeWithin:[],offset:0,direction:"top",scrollElement:null,scrollTarget:null,beforeScroll:null,afterScroll:null,easing:"swing",speed:400},d=f(location.pathname),e=function(b){var c=[],d=false,e=b.dir&&b.dir=="left"?"scrollLeft":"scrollTop";this.each(function(){if(this==document||this==window){return}var b=a(this);if(b[e]()>0){c.push(this);return}b[e](1);d=b[e]()>0;b[e](0);if(d){c.push(this);return}});if(b.el==="first"&&c.length){c=[c.shift()]}return c};a.fn.extend({scrollable:function(a){var b=e.call(this,{dir:a});return this.pushStack(b)},firstScrollable:function(a){var b=e.call(this,{el:"first",dir:a});return this.pushStack(b)},smoothScroll:function(b){b=b||{};var c=a.extend({},a.fn.smoothScroll.defaults,b);this.die("click.smoothscroll").live("click.smoothscroll",function(b){var e={},h=this,i=a(this),j=location.hostname===h.hostname||!h.hostname,k=c.scrollTarget||(f(h.pathname)||d)===d,l=g(h.hash),m=true;if(!c.scrollTarget&&(!j||!k||!l)){m=false}else{var n=c.exclude,o=0,p=n.length;while(m&&o<p){if(i.is(g(n[o++]))){m=false}}var q=c.excludeWithin,r=0,s=q.length;while(m&&r<s){if(i.closest(q[r++]).length){m=false}}}if(m){b.preventDefault();a.extend(e,c,{scrollTarget:c.scrollTarget||l,link:h});a.smoothScroll(e)}});return this}});a.smoothScroll=function(b,c){var d,e,f,g=0,h="offset",i="scrollTop",j={};if(typeof b==="number"){d=a.fn.smoothScroll.defaults;f=b}else{d=a.extend({},a.fn.smoothScroll.defaults,b||{});if(d.scrollElement){h="position";if(d.scrollElement.css("position")=="static"){d.scrollElement.css("position","relative")}}f=c||a(d.scrollTarget)[h]()&&a(d.scrollTarget)[h]()[d.direction]||0}d=a.extend({link:null},d);i=d.direction=="left"?"scrollLeft":i;if(d.scrollElement){e=d.scrollElement;g=e[i]()}else{e=a("html, body").firstScrollable()}j[i]=f+g+d.offset;if(a.isFunction(d.beforeScroll)){d.beforeScroll.call(e,d)}e.animate(j,{duration:d.speed,easing:d.easing,complete:function(){if(d.afterScroll&&a.isFunction(d.afterScroll)){d.afterScroll.call(d.link,d)}}})};a.smoothScroll.version=b;a.fn.smoothScroll.defaults=c})(jQuery)