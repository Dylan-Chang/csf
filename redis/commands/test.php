<?php

$redis = getRedis('');
var_dump($redis);

//连接redis服务器
function getRedis($redis_config){
	if(empty($redis_config)){
		//$redis_config = C('redis');
		$redis_config = array('host'=>'127.0.0.1','post'=>6379);
	}
	$redis_host = $redis_config['host'];
	$redis_port = $redis_config['port'];
	$redis_auth = $redis_config['auth'];
	if(empty($redis_host)){
		return null;
	}
	$redis = new \Redis();
	$redis->connect($redis_host,$redis_port);
	if(!empty($redis_auth)){
		$redis->auth($redis_auth);
	}
	return $redis;
}