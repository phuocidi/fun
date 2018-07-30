/**
 * SyntaxHighlighter
 * http://alexgorbatchev.com/SyntaxHighlighter
 *
 * SyntaxHighlighter is donationware. If you are using it, please donate.
 * http://alexgorbatchev.com/SyntaxHighlighter/donate.html
 *
 * @version
 * 3.0.83 (Wed, 16 Apr 2014 03:56:09 GMT)
 *
 * @copyright
 * Copyright (C) 2004-2013 Alex Gorbatchev.
 *
 * @license
 * Dual licensed under the MIT and GPL licenses.
 */
function redirect( id, lang ) {
    var contentDiv = document.getElementById( id );

    var codeDivs = contentDiv.getElementsByClassName( 'line' );
    var code = '';
    for (var i=0;i<codeDivs.length;i++ ) {
        code = code + codeDivs[i].textContent + "\r\n";
    }

    code = code.replace( /\u00A0\u00A0\u00A0\u00A0/g, '\t' );
    code = code.replace( /\u00A0/g, '' );
    code = encodeURIComponent( code );
  if(lang.includes('xml') || lang.includes('css') || lang.includes('jscript')){

    var form = document.createElement("form");
    form.setAttribute("method", "post");
    form.setAttribute("enctype", "application/x-www-form-urlencoded");
    form.setAttribute("action", "https://ide.geeksforgeeks.org/tryit.php");
    form.setAttribute("target", "_blank");

    var hiddenField1 = document.createElement("input");
    hiddenField1.setAttribute("name", "source");
    hiddenField1.setAttribute("value",(code));
    form.appendChild(hiddenField1);

    document.body.appendChild(form);
    form.submit();
    document.body.removeChild(form);

  }
  else {
    var form = document.createElement("form");
    form.setAttribute("method", "post");
    form.setAttribute("enctype", "application/x-www-form-urlencoded");
    form.setAttribute("action", "https://ide.geeksforgeeks.org/index.php");
    
    form.setAttribute("target", "_blank");
    
    var hiddenField1 = document.createElement("input");              
    hiddenField1.setAttribute("name", "source");
    hiddenField1.setAttribute("value", code );
    form.appendChild(hiddenField1);

    var hiddenField2 = document.createElement("input");              
    hiddenField2.setAttribute("name", "lang");
    hiddenField2.setAttribute("value", lang );
    form.appendChild(hiddenField2);

    document.body.appendChild(form);
    form.submit();
    document.body.removeChild(form);
  }
}

var XRegExp;if(XRegExp=XRegExp||function(e){"use strict";function t(e,t,n){var r;for(r in c.prototype)c.prototype.hasOwnProperty(r)&&(e[r]=c.prototype[r]);return e.xregexp={captureNames:t,isNative:!!n},e}function n(e){return(e.global?"g":"")+(e.ignoreCase?"i":"")+(e.multiline?"m":"")+(e.extended?"x":"")+(e.sticky?"y":"")}function r(e,r,i){if(!c.isRegExp(e))throw new TypeError("type RegExp expected");var a=p.replace.call(n(e)+(r||""),E,"");return i&&(a=p.replace.call(a,RegExp("["+i+"]+","g"),"")),e.xregexp&&!e.xregexp.isNative?t(c(e.source,a),e.xregexp.captureNames?e.xregexp.captureNames.slice(0):null):t(RegExp(e.source,a),null,!0)}function i(e,t){var n=e.length;if(Array.prototype.lastIndexOf)return e.lastIndexOf(t);for(;n--;)if(e[n]===t)return n;return-1}function a(e,t){return Object.prototype.toString.call(e).toLowerCase()==="[object "+t+"]"}function l(e){return"all"===(e=e||{})||e.all?e={natives:!0,extensibility:!0}:a(e,"string")&&(e=c.forEach(e,/[^\s,]+/,function(e){this[e]=!0},{})),e}function s(e,t,n,r){var i,a,l=m.length,s=null;H=!0;try{for(;l--;)if(a=m[l],!("all"!==a.scope&&a.scope!==n||a.trigger&&!a.trigger.call(r))&&(a.pattern.lastIndex=t,i=d.exec.call(a.pattern,e),i&&i.index===t)){s={output:a.handler.call(r,i,n),match:i};break}}catch(e){throw e}finally{H=!1}return s}function o(e){c.addToken=g[e?"on":"off"],f.extensibility=e}function u(e){RegExp.prototype.exec=(e?d:p).exec,RegExp.prototype.test=(e?d:p).test,String.prototype.match=(e?d:p).match,String.prototype.replace=(e?d:p).replace,String.prototype.split=(e?d:p).split,f.natives=e}var c,g,h,f={natives:!1,extensibility:!1},p={exec:RegExp.prototype.exec,test:RegExp.prototype.test,match:String.prototype.match,replace:String.prototype.replace,split:String.prototype.split},d={},x={},m=[],v="default",b={default:/^(?:\\(?:0(?:[0-3][0-7]{0,2}|[4-7][0-7]?)?|[1-9]\d*|x[\dA-Fa-f]{2}|u[\dA-Fa-f]{4}|c[A-Za-z]|[\s\S])|\(\?[:=!]|[?*+]\?|{\d+(?:,\d*)?}\??)/,class:/^(?:\\(?:[0-3][0-7]{0,2}|[4-7][0-7]?|x[\dA-Fa-f]{2}|u[\dA-Fa-f]{4}|c[A-Za-z]|[\s\S]))/},y=/\$(?:{([\w$]+)}|(\d\d?|[\s\S]))/g,E=/([\s\S])(?=[\s\S]*\1)/g,w=/^(?:[?*+]|{\d+(?:,\d*)?})\??/,N=p.exec.call(/()??/,"")[1]===e,S=RegExp.prototype.sticky!==e,H=!1,R="gim"+(S?"y":"");return(c=function(n,i){if(c.isRegExp(n)){if(i!==e)throw new TypeError("can't supply flags when constructing one RegExp from another");return r(n)}if(H)throw Error("can't call the XRegExp constructor within token definition functions");var a,l,o,u=[],g=v,h={hasNamedCapture:!1,captureNames:[],hasFlag:function(e){return i.indexOf(e)>-1}},f=0;if(n=n===e?"":n+"",i=i===e?"":i+"",p.match.call(i,E))throw new SyntaxError("invalid duplicate regular expression flag");for(n=p.replace.call(n,/^\(\?([\w$]+)\)/,function(e,t){if(p.test.call(/[gy]/,t))throw new SyntaxError("can't use flag g or y in mode modifier");return i=p.replace.call(i+t,E,""),""}),c.forEach(i,/[\s\S]/,function(e){if(0>R.indexOf(e[0]))throw new SyntaxError("invalid regular expression flag "+e[0])});n.length>f;)a=s(n,f,g,h),a?(u.push(a.output),f+=a.match[0].length||1):(l=p.exec.call(b[g],n.slice(f)),l?(u.push(l[0]),f+=l[0].length):(o=n.charAt(f),"["===o?g="class":"]"===o&&(g=v),u.push(o),++f));return t(RegExp(u.join(""),p.replace.call(i,/[^gimy]+/g,"")),h.hasNamedCapture?h.captureNames:null)}).addToken=(g={on:function(e,t,n){n=n||{},e&&m.push({pattern:r(e,"g"+(S?"y":"")),handler:t,scope:n.scope||v,trigger:n.trigger||null}),n.customFlags&&(R=p.replace.call(R+n.customFlags,E,""))},off:function(){throw Error("extensibility must be installed before using addToken")}}).off,c.cache=function(e,t){var n=e+"/"+(t||"");return x[n]||(x[n]=c(e,t))},c.escape=function(e){return p.replace.call(e,/[-[\]{}()*+?.,\\^$|#\s]/g,"\\$&")},c.exec=function(e,t,n,i){var a,l=r(t,"g"+(i&&S?"y":""),!1===i?"y":"");return l.lastIndex=n=n||0,a=d.exec.call(l,e),i&&a&&a.index!==n&&(a=null),t.global&&(t.lastIndex=a?l.lastIndex:0),a},c.forEach=function(e,t,n,r){for(var i,a=0,l=-1;i=c.exec(e,t,a);)n.call(r,i,++l,e,t),a=i.index+(i[0].length||1);return r},c.globalize=function(e){return r(e,"g")},c.install=function(e){e=l(e),!f.natives&&e.natives&&u(!0),!f.extensibility&&e.extensibility&&o(!0)},c.isInstalled=function(e){return!!f[e]},c.isRegExp=function(e){return a(e,"regexp")},c.matchChain=function(e,t){return function e(n,r){var i,a=t[r].regex?t[r]:{regex:t[r]},l=[],s=function(e){l.push(a.backref?e[a.backref]||"":e[0])};for(i=0;n.length>i;++i)c.forEach(n[i],a.regex,s);return r!==t.length-1&&l.length?e(l,r+1):l}([e],0)},c.replace=function(t,n,i,a){var l,s=c.isRegExp(n),o=n;return s?(a===e&&n.global&&(a="all"),o=r(n,"all"===a?"g":"","all"===a?"":"g")):"all"===a&&(o=RegExp(c.escape(n+""),"g")),l=d.replace.call(t+"",o,i),s&&n.global&&(n.lastIndex=0),l},c.split=function(e,t,n){return d.split.call(e,t,n)},c.test=function(e,t,n,r){return!!c.exec(e,t,n,r)},c.uninstall=function(e){e=l(e),f.natives&&e.natives&&u(!1),f.extensibility&&e.extensibility&&o(!1)},c.union=function(e,t){var n,r,i,l,s=/(\()(?!\?)|\\([1-9]\d*)|\\[\s\S]|\[(?:[^\\\]]|\\[\s\S])*]/g,o=0,u=function(e,t,i){var a=r[o-n];if(t){if(++o,a)return"(?<"+a+">"}else if(i)return"\\"+(+i+n);return e},g=[];if(!a(e,"array")||!e.length)throw new TypeError("patterns must be a nonempty array");for(l=0;e.length>l;++l)i=e[l],c.isRegExp(i)?(n=o,r=i.xregexp&&i.xregexp.captureNames||[],g.push(c(i.source).source.replace(s,u))):g.push(c.escape(i));return c(g.join("|"),t)},c.version="2.0.0",d.exec=function(t){var r,a,l,s,o;if(this.global||(s=this.lastIndex),r=p.exec.apply(this,arguments)){if(!N&&r.length>1&&i(r,"")>-1&&(l=RegExp(this.source,p.replace.call(n(this),"g","")),p.replace.call((t+"").slice(r.index),l,function(){var t;for(t=1;arguments.length-2>t;++t)arguments[t]===e&&(r[t]=e)})),this.xregexp&&this.xregexp.captureNames)for(o=1;r.length>o;++o)a=this.xregexp.captureNames[o-1],a&&(r[a]=r[o]);this.global&&!r[0].length&&this.lastIndex>r.index&&(this.lastIndex=r.index)}return this.global||(this.lastIndex=s),r},d.test=function(e){return!!d.exec.call(this,e)},d.match=function(e){if(c.isRegExp(e)){if(e.global){var t=p.match.apply(this,arguments);return e.lastIndex=0,t}}else e=RegExp(e);return d.exec.call(e,this)},d.replace=function(e,t){var n,r,l,s,o=c.isRegExp(e);return o?(e.xregexp&&(n=e.xregexp.captureNames),e.global||(s=e.lastIndex)):e+="",a(t,"function")?r=p.replace.call(this+"",e,function(){var r,i=arguments;if(n)for(i[0]=new String(i[0]),r=0;n.length>r;++r)n[r]&&(i[0][n[r]]=i[r+1]);return o&&e.global&&(e.lastIndex=i[i.length-2]+i[0].length),t.apply(null,i)}):(l=this+"",r=p.replace.call(l,e,function(){var e=arguments;return p.replace.call(t+"",y,function(t,r,a){var l;if(r){if(l=+r,e.length-3>=l)return e[l]||"";if(0>(l=n?i(n,r):-1))throw new SyntaxError("backreference to undefined group "+t);return e[l+1]||""}if("$"===a)return"$";if("&"===a||0==+a)return e[0];if("`"===a)return e[e.length-1].slice(0,e[e.length-2]);if("'"===a)return e[e.length-1].slice(e[e.length-2]+e[0].length);if(a=+a,!isNaN(a)){if(a>e.length-3)throw new SyntaxError("backreference to undefined group "+t);return e[a]||""}throw new SyntaxError("invalid token "+t)})})),o&&(e.lastIndex=e.global?0:s),r},d.split=function(t,n){if(!c.isRegExp(t))return p.split.apply(this,arguments);var r,i=this+"",a=t.lastIndex,l=[],s=0;return n=(n===e?-1:n)>>>0,c.forEach(i,t,function(e){e.index+e[0].length>s&&(l.push(i.slice(s,e.index)),e.length>1&&e.index<i.length&&Array.prototype.push.apply(l,e.slice(1)),r=e[0].length,s=e.index+r)}),s===i.length?(!p.test.call(t,"")||r)&&l.push(""):l.push(i.slice(s)),t.lastIndex=a,l.length>n?l.slice(0,n):l},(h=g.on)(/\\([ABCE-RTUVXYZaeg-mopqyz]|c(?![A-Za-z])|u(?![\dA-Fa-f]{4})|x(?![\dA-Fa-f]{2}))/,function(e,t){if("B"===e[1]&&t===v)return e[0];throw new SyntaxError("invalid escape "+e[0])},{scope:"all"}),h(/\[(\^?)]/,function(e){return e[1]?"[\\s\\S]":"\\b\\B"}),h(/(?:\(\?#[^)]*\))+/,function(e){return p.test.call(w,e.input.slice(e.index+e[0].length))?"":"(?:)"}),h(/\\k<([\w$]+)>/,function(e){var t=isNaN(e[1])?i(this.captureNames,e[1])+1:+e[1],n=e.index+e[0].length;if(!t||t>this.captureNames.length)throw new SyntaxError("backreference to undefined group "+e[0]);return"\\"+t+(n===e.input.length||isNaN(e.input.charAt(n))?"":"(?:)")}),h(/(?:\s+|#.*)+/,function(e){return p.test.call(w,e.input.slice(e.index+e[0].length))?"":"(?:)"},{trigger:function(){return this.hasFlag("x")},customFlags:"x"}),h(/\./,function(){return"[\\s\\S]"},{trigger:function(){return this.hasFlag("s")},customFlags:"s"}),h(/\(\?P?<([\w$]+)>/,function(e){if(!isNaN(e[1]))throw new SyntaxError("can't use integer as capture name "+e[0]);return this.captureNames.push(e[1]),this.hasNamedCapture=!0,"("}),h(/\\(\d+)/,function(e,t){if(!(t===v&&/^[1-9]/.test(e[1])&&+e[1]<=this.captureNames.length)&&"0"!==e[1])throw new SyntaxError("can't use octal escape or backreference to undefined group "+e[0]);return e[0]},{scope:"all"}),h(/\((?!\?)/,function(){return this.hasFlag("n")?"(?:":(this.captureNames.push(null),"(")},{customFlags:"n"}),"undefined"!=typeof exports&&(exports.XRegExp=c),c}(),void 0===SyntaxHighlighter)var SyntaxHighlighter=function(){function e(e){return document.createElement("div").appendChild(document.createTextNode(e)).parentNode.innerHTML.replace(/"/g,"&quot;")}function t(e,t){e.className=e.className.replace(t,"")}function n(e){return e.split(/\r?\n/)}function r(e){var t="highlighter_";return 0==e.indexOf(t)?e:t+e}function i(e){return E.vars.highlighters[r(e)]}function a(e,t,n){if(null==e)return null;var r,i,l=1!=n?e.childNodes:[e.parentNode],s={"#":"id",".":"className"}[t.substr(0,1)]||"nodeName";if(r="nodeName"!=s?t.substr(1):t.toUpperCase(),-1!=(e[s]||"").indexOf(r))return e;for(var o=0,u=l.length;l&&u>o&&null==i;o++)i=a(l[o],t,n);return i}function l(e,t){return a(e,t,!0)}function s(e,t){var n,r={};for(n in e)r[n]=e[n];for(n in t)r[n]=t[n];return r}function o(e,t,n,r){function i(e){(e=e||window.event).target||(e.target=e.srcElement,e.preventDefault=function(){this.returnValue=!1}),n.call(r||window,e)}e.attachEvent?e.attachEvent("on"+t,i):e.addEventListener(t,i,!1)}function u(e){window.alert(E.config.strings.alert+e)}function c(e,t){var n,r=E.vars.discoveredBrushes;if(null==r){r={};for(var i in E.brushes){var a=E.brushes[i],l=a.aliases;if(null!=l){a.brushName=i.toLowerCase();for(var s=0,o=l.length;o>s;s++)r[l[s]]=i}}E.vars.discoveredBrushes=r}return null==(n=E.brushes[r[e]])&&t&&u(E.config.strings.noBrush+e),n}function g(e,t){for(var r=n(e),i=0,a=r.length;a>i;i++)r[i]=t(r[i],i);return r.join("\r\n")}function h(e){for(var t,n={},r=XRegExp("^\\[(?<values>(.*?))\\]$"),i=0,a=XRegExp("(?<name>[\\w-]+)\\s*:\\s*(?<value>[\\w%#-]+|\\[.*?\\]|\".*?\"|'.*?')\\s*;?","g");null!=(t=XRegExp.exec(e,a,i));){var l=t.value.replace(/^['"]|['"]$/g,"");if(null!=l&&r.test(l)){var s=XRegExp.exec(l,r);l=s.values.length>0?s.values.split(/\s*,\s*/):[]}n[t.name]=l,i=t.index+t[0].length}return n}function f(e,t){return null==e||0==e.length||"\n"==e?e:(e=(e=e.replace(/</g,"&lt;")).replace(/ {2,}/g,function(e){for(var t="",n=0,r=e.length;r-1>n;n++)t+=E.config.space;return t+" "}),null!=t&&(e=g(e,function(e){if(0==e.length)return"";var n="";return 0==(e=e.replace(/^(&nbsp;| )+/,function(e){return n=e,""})).length?n:n+'<code class="'+t+'">'+e+"</code>"})),e)}function p(e,t){for(var n=""+e;t>n.length;)n="0"+n;return n}function d(e){return e.replace(/^\s+|\s+$/g,"")}function x(e){for(var t=n((u=e,c=void 0,c=/<br\s*\/?>|&lt;br\s*\/?&gt;/gi,1==E.config.bloggerMode&&(u=u.replace(c,"\n")),1==E.config.stripBrs&&(u=u.replace(c,"")),u)),r=/^\s*/,i=1e3,a=0,l=t.length;l>a&&i>0;a++){var s=t[a];if(0!=d(s).length){var o=r.exec(s);if(null==o)return e;i=Math.min(o[0].length,i)}}var u,c;if(i>0)for(a=0,l=t.length;l>a;a++)t[a]=t[a].substr(i);return t.join("\n")}function m(e,t){return e.index<t.index?-1:e.index>t.index?1:e.length<t.length?-1:e.length>t.length?1:0}function v(e,t){var n=null,r=[],i=t.func?t.func:function(e){return e[0]};for(pos=0;null!=(n=XRegExp.exec(e,t.regex,pos));){var a=i(n,t);"string"==typeof a&&(a=[new E.Match(a,n.index,t.css)]),r=r.concat(a),pos=n.index+n[0].length}return r}function b(e){var t="<![CDATA[",n=d(e),r=!1,i=t.length,a="]]>".length;0==n.indexOf(t)&&(n=n.substring(i),r=!0);var l=n.length;return n.indexOf("]]>")==l-a&&(n=n.substring(0,l-a),r=!0),r?n:e}function y(e){var n,r,s,u=e.target,c=l(u,".syntaxhighlighter"),g=l(u,".container"),h=document.createElement("textarea");if(g&&c&&!a(g,"textarea")){i(c.id),s=r="source",-1!=(n=c).className.indexOf(s)||(n.className+=" "+r);for(var f=g.childNodes,p=[],d=0,x=f.length;x>d;d++)p.push(f[d].innerText||f[d].textContent);p=(p=p.join("\r")).replace(/\u00a0/g," "),h.appendChild(document.createTextNode(p)),g.appendChild(h),h.focus(),h.select(),o(h,"blur",function(){h.parentNode.removeChild(h),t(c,"source")})}}"undefined"!=typeof require&&void 0===XRegExp&&(XRegExp=require("xregexp").XRegExp);var E={defaults:{"class-name":"","first-line":1,"pad-line-numbers":!1,highlight:null,title:null,"smart-tabs":!0,"tab-size":4,gutter:!0,toolbar:!0,"quick-code":!0,collapse:!1,"auto-links":!0,light:!1,unindent:!0,"html-script":!1},config:{space:"&nbsp;",useScriptTags:!0,bloggerMode:!1,stripBrs:!1,tagName:"pre",strings:{expandSource:"expand source",help:"?",alert:"SyntaxHighlighter\n\n",noBrush:"Can't find brush for: ",brushNotHtmlScript:"Brush wasn't configured for html-script option: ",aboutDialog:'<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd"><html xmlns="http://www.w3.org/1999/xhtml"><head><meta http-equiv="Content-Type" content="text/html; charset=utf-8" /><title>About SyntaxHighlighter</title></head><body style="font-family:Geneva,Arial,Helvetica,sans-serif;background-color:#fff;color:#000;font-size:1em;text-align:center;"><div style="text-align:center;margin-top:1.5em;"><div style="font-size:xx-large;">SyntaxHighlighter</div><div style="font-size:.75em;margin-bottom:3em;"><div>version 3.0.83 (Wed, 16 Apr 2014 03:56:09 GMT)</div><div><a href="http://alexgorbatchev.com/SyntaxHighlighter" target="_blank" style="color:#005896">http://alexgorbatchev.com/SyntaxHighlighter</a></div><div>JavaScript code syntax highlighter.</div><div>Copyright 2004-2013 Alex Gorbatchev.</div></div><div>If you like this script, please <a href="https://www.paypal.com/cgi-bin/webscr?cmd=_s-xclick&hosted_button_id=2930402" style="color:#005896">donate</a> to <br/>keep development active!</div></div></body></html>'}},vars:{discoveredBrushes:null,highlighters:{}},brushes:{},regexLib:{multiLineCComments:XRegExp("/\\*.*?\\*/","gs"),singleLineCComments:/\/\/.*$/gm,singleLinePerlComments:/#.*$/gm,doubleQuotedString:/"([^\\"\n]|\\.)*"/g,singleQuotedString:/'([^\\'\n]|\\.)*'/g,multiLineDoubleQuotedString:XRegExp('"([^\\\\"]|\\\\.)*"',"gs"),multiLineSingleQuotedString:XRegExp("'([^\\\\']|\\\\.)*'","gs"),xmlComments:XRegExp("(&lt;|<)!--.*?--(&gt;|>)","gs"),url:/\w+:\/\/[\w-.\/?%&=:@;#]*/g,phpScriptTags:{left:/(&lt;|<)\?(?:=|php)?/g,right:/\?(&gt;|>)/g,eof:!0},aspScriptTags:{left:/(&lt;|<)%=?/g,right:/%(&gt;|>)/g},scriptScriptTags:{left:/(&lt;|<)\s*script.*?(&gt;|>)/gi,right:/(&lt;|<)\/\s*script\s*(&gt;|>)/gi}},toolbar:{getHtml:function(e){function t(e,t){return E.toolbar.getButtonHtml(e,t,E.config.strings[t])}for(var n='<div class="toolbar">',r=E.toolbar.items,i=r.list,a=0,l=i.length;l>a;a++)n+=(r[i[a]].getHtml||t)(e,i[a]);return n+"</div>"},getButtonHtml:function(t,n,r){return'<span><a href="#" class="toolbar_item command_'+(n=e(n))+" "+n+'">'+e(r)+"</a></span>"},handler:function(e){var t,n=e.target,r=n.className||"",a=i(l(n,".syntaxhighlighter").id),s=(t=RegExp("command"+"_(\\w+)").exec(r))?t[1]:null;a&&s&&E.toolbar.items[s].execute(a),e.preventDefault()},items:{list:["expandSource","help"],expandSource:{getHtml:function(e){if(1!=e.getParam("collapse"))return"";var t=e.getParam("title");return E.toolbar.getButtonHtml(e,"expandSource",t||E.config.strings.expandSource)},execute:function(e){var n;t((n=e.id,document.getElementById(r(n))),"collapsed")}},help:{execute:function(){var e=function(e,t,n,r,i){i=(i+=", left="+(screen.width-n)/2+", top="+(screen.height-r)/2+", width="+n+", height="+r).replace(/^,/,"");var a=window.open(e,t,i);return a.focus(),a}("","_blank",500,250,"scrollbars=0"),t=e.document;t.write(E.config.strings.aboutDialog),t.close(),e.focus()}}}},findElements:function(e,t){var n=t?[t]:function(e){for(var t=[],n=0,r=e.length;r>n;n++)t.push(e[n]);return t}(document.getElementsByTagName(E.config.tagName)),r=[];if(E.config.useScriptTags&&(n=n.concat(function(){for(var e=document.getElementsByTagName("script"),t=[],n=0,r=e.length;r>n;n++)"syntaxhighlighter"==e[n].type&&t.push(e[n]);return t}())),0===n.length)return r;for(var i=0,a=n.length;a>i;i++){var l={target:n[i],params:s(e,h(n[i].className))};null!=l.params.brush&&r.push(l)}return r},highlight:function(e,t){var n=this.findElements(e,t),r=null,i=E.config;if(0!==n.length)for(var a=0,l=n.length;l>a;a++){var s,o=(t=n[a]).target,u=t.params,g=u.brush;if(null!=g){if("true"==u["html-script"]||1==E.defaults["html-script"])r=new E.HtmlScript(g),g="htmlscript";else{var h=c(g);if(!h)continue;r=new h}s=o.innerHTML,i.useScriptTags&&(s=b(s)),""!=(o.title||"")&&(u.title=o.title),u.brush=g,r.init(u),t=r.getDiv(s),""!=(o.id||"")&&(t.id=o.id),o.parentNode.replaceChild(t,o)}}},all:function(e){o(window,"load",function(){E.highlight(e)})},Match:function(e,t,n){this.value=e,this.index=t,this.length=e.length,this.css=n,this.brushName=null}};return E.Match.prototype.toString=function(){return this.value},E.HtmlScript=function(e){function t(e,t){for(var n=0,r=e.length;r>n;n++)e[n].index+=t}var n,r=c(e),i=new E.brushes.Xml,a=this,l="getDiv getHtml init".split(" ");if(null!=r){n=new r;for(var s=0,o=l.length;o>s;s++)!function(){var e=l[s];a[e]=function(){return i[e].apply(i,arguments)}}();return null==n.htmlScript?void u(E.config.strings.brushNotHtmlScript+e):void i.regexList.push({regex:n.htmlScript.code,func:function(e){for(var i,a=e.code,l=[],s=n.regexList,o=e.index+e.left.length,u=n.htmlScript,c=0,g=s.length;g>c;c++)i=v(a,s[c]),t(i,o),l=l.concat(i);null!=u.left&&null!=e.left&&(t(i=v(e.left,u.left),e.index),l=l.concat(i)),null!=u.right&&null!=e.right&&(t(i=v(e.right,u.right),e.index+e[0].lastIndexOf(e.right)),l=l.concat(i));var h=0;for(g=l.length;g>h;h++)l[h].brushName=r.brushName;return l}})}},E.Highlighter=function(){},E.Highlighter.prototype={getParam:function(e,t){var n,r,i=this.params[e];return null==(r={true:!0,false:!1}[n=null==i?t:i])?n:r},create:function(e){return document.createElement(e)},findMatches:function(e,t){var n=[];if(null!=e)for(var r=0,i=e.length;i>r;r++)"object"==typeof e[r]&&(n=n.concat(v(t,e[r])));return this.removeNestedMatches(n.sort(m))},removeNestedMatches:function(e){for(var t=0,n=e.length;n>t;t++)if(null!==e[t]){var r=e[t],i=r.index+r.length,a=t+1;for(n=e.length;n>a&&null!==e[t];a++){var l=e[a];if(null!==l){if(l.index>i)break;l.index==r.index&&l.length>r.length?e[t]=null:l.index>=r.index&&i>l.index&&(e[a]=null)}}}return e},figureOutLineNumbers:function(e){var t=[],n=parseInt(this.getParam("first-line"));return g(e,function(e,r){t.push(r+n)}),t},isLineHighlighted:function(e){var t=this.getParam("highlight",[]);return"object"!=typeof t&&null==t.push&&(t=[t]),-1!=function(e,t,n){for(var r=n=Math.max(n||0,0),i=e.length;i>r;r++)if(e[r]==t)return r;return-1}(t,""+e)},getLineHtml:function(e,t,n){var r=["line","number"+t,"index"+e,"alt"+(0==t%2?1:2)];return this.isLineHighlighted(t)&&r.push("highlighted"),0==t&&r.push("break"),'<div class="'+r.join(" ")+'">'+n+"</div>"},getLineNumbersHtml:function(e,t){var r="",i=n(e).length,a=parseInt(this.getParam("first-line")),l=this.getParam("pad-line-numbers");1==l?l=(""+(a+i-1)).length:1==isNaN(l)&&(l=0);for(var s=0;i>s;s++){var o=t?t[s]:a+s;e=0==o?E.config.space:p(o,l);r+=this.getLineHtml(s,o,e)}return r},getCodeLinesHtml:function(e,t){for(var r=n(e=d(e)),i=(this.getParam("pad-line-numbers"),parseInt(this.getParam("first-line"))),a=(e="",this.getParam("brush")),l=0,s=r.length;s>l;l++){var o=r[l],u=/^(&nbsp;|\s)+/.exec(o),c=null,g=t?t[l]:i+l;null!=u&&(c=""+u[0],o=o.substr(c.length),c=c.replace(" ",E.config.space)),0==(o=d(o)).length&&(o=E.config.space),e+=this.getLineHtml(l,g,(null!=c?'<code class="'+a+' spaces">'+c+"</code>":"")+o)}return e},getTitleHtml:function(t){return t?"<caption>"+e(t)+"</caption>":""},getMatchesHtml:function(e,t){function n(e){var t=e&&e.brushName||a;return t?t+" ":""}for(var r=0,i="",a=this.getParam("brush",""),l=0,s=t.length;s>l;l++){var o,u=t[l];null!==u&&0!==u.length&&(o=n(u),i+=f(e.substr(r,u.index-r),o+"plain")+f(u.value,o+u.css),r=u.index+u.length+(u.offset||0))}return i+f(e.substr(r),n()+"plain")},getHtml:function(t){var i,a,l,s,o,u="",c=["syntaxhighlighter"];return 1==this.getParam("light")&&(this.params.toolbar=this.params.gutter=!1),className="syntaxhighlighter",1==this.getParam("collapse")&&c.push("collapsed"),0==(gutter=this.getParam("gutter"))&&c.push("nogutter"),c.push(this.getParam("class-name")),c.push(this.getParam("brush")),t=(o=t,o.replace(/^[ ]*[\n]+|[\n]*[ ]*$/g,"")).replace(/\r/g," "),i=this.getParam("tab-size"),t=1==this.getParam("smart-tabs")?function(e,t){for(var r=(n(e),"\t"),i="",a=0;50>a;a++)i+="                    ";return g(e,function(e){if(-1==e.indexOf(r))return e;for(var n=0;-1!=(n=e.indexOf(r));)l=n,s=t-n%t,e=(a=e).substr(0,l)+i.substr(0,s)+a.substr(l+1,a.length);var a,l,s;return e})}(t,i):function(e,t){for(var n="",r=0;t>r;r++)n+=" ";return e.replace(/\t/g,n)}(t,i),this.getParam("unindent")&&(t=x(t)),gutter&&(l=this.figureOutLineNumbers(t)),a=this.findMatches(this.regexList,t),u=this.getMatchesHtml(t,a),u=this.getCodeLinesHtml(u,l),this.getParam("auto-links")&&(s=/(.*)((&gt;|&lt;).*)/,u=u.replace(E.regexLib.url,function(e){var t,n="";return(t=s.exec(e))&&(e=t[1],n=t[2]),'<a href="'+e+'">'+e+"</a>"+n})),"undefined"!=typeof navigator&&navigator.userAgent&&navigator.userAgent.match(/MSIE/)&&c.push("ie"),'<div id="'+r(this.id)+'" class="'+e(c.join(" "))+'">'+(this.getParam("toolbar")?E.toolbar.getHtml(this):"")+'<table border="0" cellpadding="0" cellspacing="0">'+this.getTitleHtml(this.getParam("title"))+"<tbody><tr>"+(gutter?'<td class="gutter">'+this.getLineNumbersHtml(t)+"</td>":"")+'<td class="code"><div class="container">'+u+"</div></td></tr></tbody></table>"+(t?'<button class="runIdeBtn" onclick="redirect( \''+r(this.id)+"', '"+this.getParam("brush")+"' )\">Run on IDE</button>":"")+"</div>"},getDiv:function(e){null===e&&(e=""),this.code=e;var t=this.create("div");return t.innerHTML=this.getHtml(e),this.getParam("toolbar")&&o(a(t,".toolbar"),"click",E.toolbar.handler),this.getParam("quick-code")&&o(a(t,".code"),"dblclick",y),t},init:function(e){var t,n;this.id=(n||"")+""+Math.round(1e6*Math.random()),t=this,E.vars.highlighters[r(t.id)]=t,this.params=s(E.defaults,e||{}),1==this.getParam("light")&&(this.params.toolbar=this.params.gutter=!1)},getKeywords:function(e){return"\\b(?:"+(e=e.replace(/^\s+|\s+$/g,"").replace(/\s+/g,"|"))+")\\b"},forHtmlScript:function(e){var t={end:e.right.source};e.eof&&(t.end="(?:(?:"+t.end+")|$)"),this.htmlScript={left:{regex:e.left,css:"script"},right:{regex:e.right,css:"script"},code:XRegExp("(?<left>"+e.left.source+")(?<code>.*?)(?<right>"+t.end+")","sgi")}}},E}();"undefined"!=typeof exports&&(exports.SyntaxHighlighter=SyntaxHighlighter);
