<?php
/*
��3-9 һЩ���õ����򼯺�����
���� 	����������
ZADD 	ZADD key-name score member [score member ...]���������и�����ֵ�ĳ�Ա��ӵ����򼯺�����
ZREM 	ZREM key-name member [member ...]���������򼯺������Ƴ������ĳ�Ա�������ر��Ƴ���Ա������
ZCARD 	ZCARD key-name�����������򼯺ϰ����ĳ�Ա����
ZINCRBY 	ZINCRBY key-name increment member������member��Ա�ķ�ֵ����increment
ZCOUNT 	ZCOUNT key-name min max�������ط�ֵ����min��max֮��ĳ�Ա����
ZRANK 	ZRANK key-name member�������س�Աmember��key-name�е�����
ZSCORE 	ZSCORE key-name member�������س�Աmember�ķ�ֵ
ZRANGE 	ZRANGE key-name start stop [WITHSCORES]�����������򼯺�����������start��stop֮��ĳ�Ա����������˿�ѡ��WITHSCORESѡ���ô����Ὣ��Ա�ķ�ֵҲһ������
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
echo $redis->zcount('zset-key',0,3); # ����ĳЩ������˵��ͳ�Ƹ�����ֵ��Χ�ڵ�Ԫ�������ǳ����á�
echo '<br>';
echo $redis->zrem('zset-key','b');
echo '<br>';
print_r($redis->zrange('zset-key',0,-1,withscores)); # �ڽ��е���ʱ������ͨ����ʹ��ZRANGEȡ�����򼯺������������Ԫ�أ�������ʵ�������У�ͨ��һ��ֻ��ȡ��һС����Ԫ�ء�






