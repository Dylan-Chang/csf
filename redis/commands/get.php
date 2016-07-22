<?php
$redis = new redis();
$redis->connect('127.0.0.1',6379);
$result = $redis->get('test');
var_dump($result);