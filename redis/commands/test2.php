<?php
$redis = new redis();
//实例连接到一个Redis.
$redis->connect('127.0.0.1',6379);
//设置key和value的值
$redis->set('test','111111111');
//获取有关指定键的值
$result = $redis->get('test');
//删除指定的键
$redis->delete('test');
//如果在数据库中不存在该键，设置关键值参数
$redis->setnx('test','2222222');
//验证指定的键是否存在
$redis->existe('test');
//数字递增存储键值键
var_dump($redis->incr('test'));
var_dump($redis->incr('test'));
//数字递减存储键值
var_dump($redis->decr('test'));
var_dump($redis->decr('test'));
//取得所有指定键的值。如果一个或多个键不存在，该数组中该键的值为假
$redis->set('test1','123');
$redis->set('test2','456');
$redis->getMultiple(array('test1','test2'));

var_dump($result);