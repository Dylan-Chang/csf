<?php
/*
3.2 �б�
���� 	����������
RPUSH 	RPUSH key-name value [value ...]������һ������ֵ���뵽�б���Ҷ�
LPUSH 	LPUSH key-name value [value ...]������һ������ֵ���뵽�б�����
RPOP 	RPOP key-name�����Ƴ��������б����Ҷ˵�Ԫ��
LPOP 	LPOP key-name�����Ƴ��������б�����˵�Ԫ��
LINDEX 	LINDEX key-name offset���������б���ƫ����Ϊoffset��Ԫ��
LRANGE 	LRANGE key-name start end���������б��startƫ������endƫ������Χ�ڵ�����Ԫ�أ�����start��end
LTRIM 	LTRIM key-name start end�������б�����޼���ֻ������startƫ������endƫ������Χ�ڵ�Ԫ�أ�����start��end
*/


//�������ʾ��չʾ��Redis�б����������͵�������
$redis = new redis();
$redis->connect('127.0.0.1',6379);
echo $redis->rpush('list-key','last'); # �����б�����Ԫ��ʱ��
echo '<br>';
echo $redis->lpush('list-key','first'); # ���Ժ����׵ض��б������ִ�����������
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
print_r($redis->rpush('list-key','a','b','c'));# ����ͬʱ������Ԫ�ء�
echo '<br>';
print_r($redis->lrange('list-key',0,-1));
echo '<br>';
print_r($redis->ltrim('list-key',2,-1));  # ���Դ��б����ˡ��Ҷ˻�����������ɾ������������Ԫ�ء�
echo '<br>';
print_r($redis->lrange('list-key',0,-1));
echo '<br>';
