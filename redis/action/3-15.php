<?php
// չʾRedis�й���ʱ����ص������ʹ��
$conn = new redis();
$conn->connect('127.0.0.1',6379);
echo $conn->set('key','value'); # ����һ���򵥵��ַ���ֵ����Ϊ����ʱ������ö���
echo "<br>";
echo $conn->get('key');
echo "<br>";
echo $conn->expire('key',2);   # �������Ϊ�������˹���ʱ�䣬��ô�������ں�
echo "<br>";
sleep(4);
echo $conn->get('key'); # �����ٳ���ȥ��ȡ��ʱ���ᷢ�ּ��Ѿ���ɾ���ˡ�
echo "<br>";
echo $conn->set('key','value2');
echo "<br>";
echo $conn->expire('key',100); 
echo "<br>";
sleep(4);
echo $conn->ttl('key'); # �����Ժ����׵ز鵽���������ʱ�仹�ж�á�
echo "<br>";