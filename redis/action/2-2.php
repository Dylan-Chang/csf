<?php
function connectRedis(){
	$redis = new redis();
    $redis->connect('127.0.0.1',6379);
	return $redis;
}

//使用Redis实现购物车
function add_to_cart($conn,$session,$item,$count){
	if($count <= 0){
		$conn->hrem('cart:'+$session,$item);
	}else{
		$conn->hset('cart:'+$session,$item,$count);
	}
}