<!--(c) Copyright 2017 sang8052. All Rights Reserved.  2017-08-17-->
<!doctype html>
<html class="no-js">
<head>
  <meta charset="utf-8">
  <meta http-equiv="X-UA-Compatible" content="IE=edge">
  <meta name="keywords" content=""><!--此页面的关键字-->
  <meta name="viewport" content="width=device-width, initial-scale=1,width=device-width, initial-scale=1, maximum-scale=1, user-scalable=no">
  <!--Amaze UI 以移动优先的理念开发，需要在 meta 中设置相关 viewport 属性。width=device-width, initial-scale=1 是必须的，而且我们认为好的设计是不需要用户去操作窗口缩放的，所以加上了 maximum-scale=1, user-scalable=no-->
  <title></title>
  <meta name="renderer" content="webkit"><!--360浏览器渲染功能加强-->
  <meta http-equiv="Cache-Control" content="no-siteapp"/>  <!--垃圾广告屏蔽-->
  <!--按照下面的注释写你的移动适配页面-->
  <!--<link rel="canonical" href="http://www.example.com/">-->
  <!--Amaze UI CSS 代码引入-->
  <link rel="stylesheet" href="UI/css/amazeui.min.css">
  <link rel="stylesheet" href="UI/css/app.css">
</head>
<body STYLE="BACKGROUND-COLOR:#ECE9D8;">
<div style="position: relative;">
<?php
	if(isset($_GET['keyvalue'])&&isset($_GET['keypass']))
	{
		$keyvalue=$_GET['keyvalue'];
		$keypass=$_GET['keypass'];
	echo '<img src="http://qr.topscan.com/api.php?w=150&text=http://mysscloud.xyz/index.php?keyvalue='.$keyvalue.'%26keypass='.$keypass.'" style="position:absolute;top:0;left:0" />';
	}
	
?>
</div>
</body>
</html>