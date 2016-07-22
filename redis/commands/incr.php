<?php
$redis = new redis();
$redis->connect('127.0.0.1',6379);
$redis->set('test','123');
var_dump($redis->incr("test"));
var_dump($redis->incr("test"));
