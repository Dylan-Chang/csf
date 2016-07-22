<?php
/*
表3-9 一些常用的有序集合命令
命令 	用例和描述
ZADD 	ZADD key-name score member [score member ...]——将带有给定分值的成员添加到有序集合里面
ZREM 	ZREM key-name member [member ...]——从有序集合里面移除给定的成员，并返回被移除成员的数量
ZCARD 	ZCARD key-name——返回有序集合包含的成员数量
ZINCRBY 	ZINCRBY key-name increment member——将member成员的分值加上increment
ZCOUNT 	ZCOUNT key-name min max——返回分值介于min和max之间的成员数量
ZRANK 	ZRANK key-name member——返回成员member在key-name中的排名
ZSCORE 	ZSCORE key-name member——返回成员member的分值
ZRANGE 	ZRANGE key-name start stop [WITHSCORES]——返回有序集合中排名介于start和stop之间的成员，如果给定了可选的WITHSCORES选项，那么命令会将成员的分值也一并返回
*/
$redis = new redis();
$redis->connect('127.0.0.1',6379);
echo $redis->zadd('zset-key','a',3,'b',2,'c',1);
echo "<br>";
echo $redis->zcard('zset-key');
echo "<br>";
echo $redis->zincrby('zset-key','c',3);
echo "<br>";
echo $redis->zscore('zset-key','b');
echo "<br>";
echo $redis->zrank('zset-key','c');
echo "<br>";
echo $redis->zcount('zset-key',0,3); # 对于某些任务来说，统计给定分值范围内的元素数量非常有用。
echo '<br>';
echo $redis->zrem('zset-key','b');
echo '<br>';
print_r($redis->zrange('zset-key',0,-1,withscores)); # 在进行调试时，我们通常会使用ZRANGE取出有序集合里包含的所有元素，但是在实际用例中，通常一次只会取出一小部分元素。






