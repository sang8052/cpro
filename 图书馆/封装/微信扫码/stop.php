<!--(c) Copyright 2017 sang8052. All Rights Reserved.  2017-08-17-->
<!doctype html>
<html class="no-js">
<head>
  <meta charset="utf-8">
  <meta http-equiv="X-UA-Compatible" content="IE=edge">
  <meta name="description" content=""><!--此页面的描述-->
  <meta name="keywords" content=""><!--此页面的关键字-->
  <meta name="viewport" content="width=device-width, initial-scale=1,width=device-width, initial-scale=1, maximum-scale=1, user-scalable=no">
  <!--Amaze UI 以移动优先的理念开发，需要在 meta 中设置相关 viewport 属性。width=device-width, initial-scale=1 是必须的，而且我们认为好的设计是不需要用户去操作窗口缩放的，所以加上了 maximum-scale=1, user-scalable=no-->
  <title>维护通告</title>
  <meta name="renderer" content="webkit"><!--360浏览器渲染功能加强-->
  <meta http-equiv="Cache-Control" content="no-siteapp"/>  <!--垃圾广告屏蔽-->
  <link rel="icon" type="image/png" href="UI/i/favicon.ico"><!--设置网页的logo-->
  <!-- 安卓浏览器配置，工具栏和图标 -->
  <meta name="mobile-web-app-capable" content="yes">
  <link rel="icon" sizes="192x192" href="UI/img/Library_512px.png">
  <!-- 安卓浏览器配置，工具栏和图标 -->
  <meta name="apple-mobile-web-app-capable" content="yes">
  <meta name="apple-mobile-web-app-status-bar-style" content="black">
  <meta name="apple-mobile-web-app-title" content="维护通告"/>
  <link rel="apple-touch-icon-precomposed" href="UI/img/Library_512px.png">
  <!-- win8浏览器配置 图标和工具栏配色 -->
  <meta name="msapplication-TileImage" content="UI/img/Library_512px.png">
  <meta name="msapplication-TileColor" content="#0e90d2">
  <!--按照下面的注释写你的移动适配页面-->
  <!--<link rel="canonical" href="http://www.example.com/">-->
  <!--Amaze UI CSS 代码引入-->
  <link rel="stylesheet" href="UI/css/amazeui.min.css">
  <link rel="stylesheet" href="UI/css/app.css">
</head>
<body>

	 
		<div id="web_bg" style="position:absolute; width:100%; height:100%; z-index:-1"> 
    <img style="position:fixed;" src="UI/img/backpic.jpg" height="100%" width="100%" /> 
    </div>
    <div class=" am-vertical-align" style="height: 500px; " align="center">
    <div class="am-vertical-align-middle" >
     <p><?php 
	  	  require("conn.php");
		    require("fun.php");
	  	  $sql="select * from `sys` where `setname`='appoffres'";
		        $row=selectmysql($sql);
		    	echo $row['setvalue'];

		    ?>
    </p>
    <p>版本：&nbsp;<?php $sql="select * from `sys` where `setname`='webversion'";
		        $row=selectmysql($sql);
		    	echo $row['setvalue'];?><br/>
Copyright © 2017 wt-dk.com,  software engineering class four of Information Engineering Department belong Nanjing Aerospace University, Jincheng Institute All rights reserved.
		    	</p>
    </div></div>
	
    

<!--[if (gte IE 9)|!(IE)]><!-->
<script src="UI/js/jquery.min.js"></script>
<!--<![endif]-->
<!--[if lte IE 8 ]>
<script src="http://libs.baidu.com/jquery/1.11.3/jquery.min.js"></script>
<script src="http://cdn.staticfile.org/modernizr/2.8.3/modernizr.js"></script>
<script src="UI/js/amazeui.ie8polyfill.min.js"></script>
<![endif]-->
<script src="UI/js/amazeui.min.js"></script>


</body>
</html>
