<?php
/*
表3-12 SORT命令的定义
命令 	用例和描述
SORT 	SORT source-key [BY pattern] [LIMIT offset count] [GET pattern [GET pattern ...]] 
        [ASC|DESC] [ALPHA] [STORE dest-key] 
        ——根据给定的选项，对输入列表、集合或者有序集合进行排序，然后返回或者存储排序的结果
*/

$redis = new redis();
$redis->connect('127.0.0.1',6379);
$redis->rpush('sort-input',23,15,110,7);# 首先将一些元素添加到列表里面。
print_r($redis->sort('sort-input'));
echo '<br>';
print_r($redis->sort('sort-input',alpha));
echo '<br>';
echo $redis->hset('d-7','field',5);
echo '<br>';
echo $redis->hset('d-15','field',1);
echo '<br>';
echo $redis->hset('d-23','field',9);
echo '<br>';
echo $redis->hset('d-110','field',3);
echo '<br>';
print_r($redis->sort('sort-input','d-*->field'));
echo '<br>';
print_r($redis->sort('sort-input','d-*->field','d-*->field'));
echo '<br>';
