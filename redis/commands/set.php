<?php
$redis = new redis();
$redis->connect('127.0.0.1',6379);
$result = $redis->set('test1','11111111');
var_dump($result);
exit;