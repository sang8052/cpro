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
  <title>欢迎使用图书馆系统——微信借还书功能</title>
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
	  	  $nowtime=nowtime();
	  	  $keyvalue=$keypass='0';
	  	  if(isset($_GET['keyvalue'])){$keyvalue=$_GET['keyvalue']; } 
		    if(isset($_GET['keypass'])){$keypass=$_GET['keypass']; } 
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
		      	}
		    }}
		    else{
		    	$state="授权失败";
		    	$alertecho="您的授权信息不正确！请在图书馆系统中重试刷新授权码，并重新使用微信扫码授权！";
		    	echoalert_text($alertecho);
		    }}
		    ?>
		<div id="web_bg" style="position:absolute; width:100%; height:100%; z-index:-1"> 
    <img style="position:fixed;" src="UI/img/backpic.jpg" height="100%" width="100%" /> 
    </div>
		<div class=" am-vertical-align" style="height: 500px; " align="center">
    <div class="am-vertical-align-middle" >
	   <table class="am-table am-table-bordered am-table-radius "  >
		<thead><tr><td colspan="2" align="center">欢迎使用图书馆系统——微信借还书功能</td></tr></thead>
		<tbody>
		<tr><td colspan="2" align="center">您目前的授权状态为：&nbsp;<?php echo $state;if(isset($limittime)){echo "<br/>您的授权截止时间为：".$limittime;}  ?></td></tr>
		<tr>
			<?php 
				    if($state=="授权成功")
				    {
				    	$lendecho='lend.php?keyvalue='.$keyvalue.'&keypass='.$keypass; 
				     $returnecho='return.php?keyvalue='.$keyvalue.'&keypass='.$keypass;
				     }
				     else
				     {
				     	$lendecho='#'; 
				     $returnecho='#';;
				     }
				     ?>
			<td align="center"><a class="am-btn am-btn-success" href="<?php echo $lendecho;?>" target="_blank">借书扫码</a></td>
			<td align="center"><a class="am-btn am-btn-warning" href="<?php echo $returnecho;?>" target="_blank">还书扫码</a></td>
			</tr>
			<tr><td colspan="2" align="center">版本：&nbsp<?php $sql="select * from `sys` where `setname`='webversion'";
		        $row=selectmysql($sql);
		    	echo $row['setvalue'];?></td></tr>
			<tr><td colspan="2" align="center">Copyright © 2017 wt-dk.com,  software engineering class four of Information Engineering Department belong Nanjing Aerospace University, Jincheng Institute All rights reserved. </td></tr>
	  </tbody>
	  </table>
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
