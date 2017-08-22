
<?php
function selectmysql($sql) //查询数据库
{
	mysql_query($sql) or die ("查询数据库失败 原因：".mysql_error());
	if(mysql_query($sql)){$result=mysql_fetch_array(mysql_query($sql));}
	else{$result='';}
	return $result;
	
}

function updatemysql($sql) //更新数据库
{
	mysql_query($sql) or die ("更新数据库失败 原因：".mysql_error());
	
	
}
function echoalert_text($text)//弹出对话框-只有内容
{
	$echo='<script language="javascript">{ alert("'.$text.'");} </script>';
	echo $echo;
}

function echoalert_url($url)//跳转到网址
{
	$echo='<script language="javascript">{ window.location.href="'.$url.'";} </script>';
	echo $echo;
}

function echoalert_text_url($text,$url)//弹出对话框点击确定之后跳转到网址
{
	$echo='<script language="javascript">{ alert("'.$text.'"); window.location.href="'.$url.'";} </script>';
	echo $echo;
}

function nowtime()//返回当前时间和日期
{
	date_default_timezone_set("Asia/Shanghai");
	$date=date("Y-m-d H:i:s");
	return $date;
}
?>