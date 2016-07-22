<?php
$redis = new redis();
$redis->connect('127.0.0.1',6379);
$redis->set('test1','111111');
var_dump($redis->get('test1'));
$redis->delete('test1');
var_dump($redis->get('test1'));
