<?php
//返回列表 key 的长度。
$redis = new redis();
$redis->connect('127.0.0.1',6379);
//$redis->lpush('mylist','World');
//$redis->lpush('mylist','Hello');
var_dump($redis->LLEN('mylist'));