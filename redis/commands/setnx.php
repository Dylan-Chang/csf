<?php
$redis = new redis();
$redis->connect('127.0.0.1',6379);
$redis->set('test','1111111111111111111');
$redis->setnx('test','22222222222');
echo $redis->get('test');
$redis->delete('test');
$redis->setnx('test','22222222222');
echo $redis->get('test');
