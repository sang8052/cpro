<!--(c) Copyright 2017 sang8052. All Rights Reserved.  2017-08-17-->
<!doctype html>
<html class="no-js">
<head>
  <meta charset="utf-8">
  <meta http-equiv="X-UA-Compatible" content="IE=edge">
  <meta name="description" content="此系统只能在微信浏览器中才能正确运行"><!--此页面的描述-->
  <meta name="keywords" content=""><!--此页面的关键字-->
  <meta name="viewport" content="width=device-width, initial-scale=1,width=device-width, initial-scale=1, maximum-scale=1, user-scalable=no">
  <!--Amaze UI 以移动优先的理念开发，需要在 meta 中设置相关 viewport 属性。width=device-width, initial-scale=1 是必须的，而且我们认为好的设计是不需要用户去操作窗口缩放的，所以加上了 maximum-scale=1, user-scalable=no-->
  <title>欢迎使用图书馆系统——处理页面</title>
  <meta name="renderer" content="webkit"><!--360浏览器渲染功能加强-->
  <meta http-equiv="Cache-Control" content="no-siteapp"/>  <!--垃圾广告屏蔽-->
  <link rel="icon" type="image/png" href="UI/i/favicon.ico"><!--设置网页的logo-->
  <!-- 安卓浏览器配置，工具栏和图标 -->
  <meta name="mobile-web-app-capable" content="yes">
  <link rel="icon" sizes="192x192" href="UI/img/Library_512px.png">
  <!-- 安卓浏览器配置，工具栏和图标 -->
  <meta name="apple-mobile-web-app-capable" content="yes">
  <meta name="apple-mobile-web-app-status-bar-style" content="black">
  <meta name="apple-mobile-web-app-title" content="欢迎使用图书馆系统——微信借还书功能"/>
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
<?php 
require("conn.php");
require("fun.php");
if(isset($_GET['keyvalue'])){$keyvalue=$_GET['keyvalue'];} 
if(isset($_GET['keypass'])){$keypass=$_GET['keypass'];} 
if(isset($_GET['qrstate'])){$qrstate=$_GET['qrstate'];} 
if(isset($_GET['outqr'])){$outqr=$_GET['outqr'];} 
$sql="select * from `sys` where `setname`='apponoff'";
		    $row=selectmysql($sql);
		    if($row['setvalue']=='off')
		    {
		    $url="http://mysscloud.xyz/stop.php";
		     echoalert_url($url);
		    	}
		    	else{
$sql="select * from `appkey` where `keyvalue` = '$keyvalue'";
$row=selectmysql($sql);
if($row!=''){if($keypass==$row['keypass'])
{ $limittime=$row['limittime'];
if(strtotime($limittime)>strtotime($nowtime)&&$row['keystate']==1)
{$state="授权成功";}
else{
	$sql="update appkey set keystate=0 where keyvalue='".$keyvalue."'";
	updatemysql($sql);
$state="授权失败";
$alertecho="您的授权时间已经过期，请在图书馆系统中刷新授权码，并重新使用微信扫码授权！";
echoalert_text($alertecho);
}}}
else{
$state="授权失败";
$alertecho="您的授权信息不正确！请在图书馆系统中重试刷新授权码，并重新使用微信扫码授权！";
echoalert_text($alertecho);
}
if($state=="授权成功")
{
	$nowtime=nowtime();
	$sql="select * from user where keyvalue='".$keyvalue."'";
	$row=selectmysql($sql);
	$lenduser=$row['username'];
	
  $sql="select * from booknum where booknum='".$outqr."'";
 $sqlnum=mysql_num_rows(mysql_query($sql));
  if($sqlnum=='1')
  {if($qrstate=='lend')
	{
		$sql="select * from booknum where booknum='".$outqr."'";
		$row=selectmysql($sql);
		if($row['bookstate']=='1'){$alertecho="借书失败！此书已经被借出！";}
		else{$sql="update booknum  set bookstate='1',lendtime='".$nowtime."',lenduser='".$lenduser."'where booknum='".$outqr."'";
		updatemysql($sql);
		$alertecho="借书成功！";}
		
	}
	if($qrstate=='return')
	{
		$sql="select * from booknum where booknum='".$outqr."'";
		$row=selectmysql($sql);
		if($row['bookstate']=='0'){$alertecho="还书失败！此书尚未被借出！";}
		else{$sql="update booknum  set bookstate='0',lendtime='',lenduser=''where booknum='".$outqr."'";
		
		updatemysql($sql);
		$alertecho="还书成功！";}
	}
	}
	else{ $alertecho="图书号出错，未找到对应书籍！";}
  
	
	$url="http://mysscloud.xyz/index.php?keyvalue=".$keyvalue."&keypass=".$keypass;
	echoalert_text($alertecho);
	echoalert_url($url);
	
}}



?>
	  	 
    

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
