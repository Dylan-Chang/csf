<?php
function connectRedis(){
	$redis_host = '127.0.0.1';
	$redis_port = '6379';
	$redis_auth = '';
	
	$redis = \new Redis();
	$redis = $redis->connect($redis_host,$redis_port);
	return $redis;
}

function check($ip){
	$redis_service = connectRedis();
	//$redis_service->select(1);//ѡ�����ݿ�
	
	$redis_key = 'visit:ip:list:'.$ip;
	$current = $redis_service->lLen($redis_key)//�����б�key�ĳ���
	
}

