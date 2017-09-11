<?php
  $mysql_server="47.94.219.254"; //数据库服务器名称
  $mysql_username="cpro"; // 连接数据库用户名
  $mysql_password="c4xtYfjpTN"; // 连接数据库密码
  $mysql_database="cpro"; // 数据库的名字
  $conn=mysql_connect($mysql_server, $mysql_username,$mysql_password) or die("初始化数据库连接出错，错误内容：".mysql_error());
  mysql_select_db($mysql_database,$conn);//选择某个数据库
  mysql_query("set names 'utf8'");//设置数据库字符集 utf-8
  
?>