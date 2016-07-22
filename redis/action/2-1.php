<?php
/**
 * 登录和cookie缓存
 */

function connectRedis(){
	$redis = new redis();
$redis->connect('127.0.0.1',6379);
	return $redis;
}

$conn = connectRedis();
$rs = check_token($conn,'123123');
var_dump($rs);exit;

function check_token($conn,$token){
	return $conn->hGet('login',$token); # 尝试获取并返回令牌对应的用户。
}

//更新令牌
function update_token($conn,$token,$user,$item){
	# 获取当前时间戳。
	$timestemp = time();
	# 维持令牌与已登录用户之间的映射。
	$conn->hset('login:',$token,$user);
	# 记录令牌最后一次出现的时间。
	$conn->zadd('recent:',$token,$timestamp);
	if($item){
		# 记录用户浏览过的商品。
		$conn->zadd('viewed:'.$token,$item,$timestamp);
		# 移除旧的记录，只保留用户最近浏览过的25个商品。
		$conn->zremrangebyrank('viewed:'.$token,0,-26);
	}
}



