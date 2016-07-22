<?php
// 展示Redis中过期时间相关的命令的使用
$conn = new redis();
$conn->connect('127.0.0.1',6379);
echo $conn->set('key','value'); # 设置一个简单的字符串值，作为过期时间的设置对象。
echo "<br>";
echo $conn->get('key');
echo "<br>";
echo $conn->expire('key',2);   # 如果我们为键设置了过期时间，那么当键过期后，
echo "<br>";
sleep(4);
echo $conn->get('key'); # 我们再尝试去获取键时，会发现键已经被删除了。
echo "<br>";
echo $conn->set('key','value2');
echo "<br>";
echo $conn->expire('key',100); 
echo "<br>";
sleep(4);
echo $conn->ttl('key'); # 还可以很容易地查到键距离过期时间还有多久。
echo "<br>";