<?php
/*
3.2 列表
命令 	用例和描述
RPUSH 	RPUSH key-name value [value ...]——将一个或多个值推入到列表的右端
LPUSH 	LPUSH key-name value [value ...]——将一个或多个值推入到列表的左端
RPOP 	RPOP key-name——移除并返回列表最右端的元素
LPOP 	LPOP key-name——移除并返回列表最左端的元素
LINDEX 	LINDEX key-name offset——返回列表中偏移量为offset的元素
LRANGE 	LRANGE key-name start end——返回列表从start偏移量到end偏移量范围内的所有元素，包括start和end
LTRIM 	LTRIM key-name start end——对列表进行修剪，只保留从start偏移量到end偏移量范围内的元素，包括start和end
*/


//这个交互示例展示了Redis列表的推入操作和弹出操作
$redis = new redis();
$redis->connect('127.0.0.1',6379);
echo $redis->rpush('list-key','last'); # 在向列表推入元素时，
echo '<br>';
echo $redis->lpush('list-key','first'); # 可以很容易地对列表的两端执行推入操作。
echo '<br>';
echo $redis->rpush('list-key','new last'); 
echo '<br>';
print_r($redis->lrange('list-key',0,-1));
echo '<br>';
echo $redis->lpop('list-key');
echo '<br>';
echo $redis->lpop('list-key');
echo '<br>';
print_r($redis->lrange('list-key',0,-1));
echo '<br>';
print_r($redis->rpush('list-key','a','b','c'));# 可以同时推入多个元素。
echo '<br>';
print_r($redis->lrange('list-key',0,-1));
echo '<br>';
print_r($redis->ltrim('list-key',2,-1));  # 可以从列表的左端、右端或者左右两端删减任意数量的元素。
echo '<br>';
print_r($redis->lrange('list-key',0,-1));
echo '<br>';
