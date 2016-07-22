<?php
/*
表3-11 Redis提供的发布与订阅命令
命令 	用例和描述
SUBSCRIBE 	SUBSCRIBE channel [channel ...]——订阅给定的一个或多个频道
UNSUBSCRIBE 	UNSUBSCRIBE [channel [channel ...]]——退订给定的一个或多个频道，如果执行时没有给定任何频道，那么退订所有频道
PUBLISH 	PUBLISH channel message——向给定频道发送消息
PSUBSCRIBE 	PSUBSCRIBE pattern [pattern ...]——订阅与给定模式相匹配的所有频道
PUNSUBSCRIBE 	PUNSUBSCRIBE [pattern [pattern ...]]——退订给定的模式，如果执行时没有给定任何模式，那么退订所有模式
*/
function conn_redis(){
	$redis = new redis();
    $redis->connect('127.0.0.1',6379); 
	return $redis;
}

function publisher($n){
	sleep(1);
	foreach($i as range($n)){
		$redis = conn_redis();
		sleep(1);
	}
}

function run_pubsub(){
	//因为用到多线程 暂不编写
	
}



