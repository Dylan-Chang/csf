<?php
/*
��3-12 SORT����Ķ���
���� 	����������
SORT 	SORT source-key [BY pattern] [LIMIT offset count] [GET pattern [GET pattern ...]] 
        [ASC|DESC] [ALPHA] [STORE dest-key] 
        �������ݸ�����ѡ��������б����ϻ������򼯺Ͻ�������Ȼ�󷵻ػ��ߴ洢����Ľ��
*/

$redis = new redis();
$redis->connect('127.0.0.1',6379);
$redis->rpush('sort-input',23,15,110,7);# ���Ƚ�һЩԪ����ӵ��б����档
print_r($redis->sort('sort-input'));
echo '<br>';
print_r($redis->sort('sort-input',alpha));
echo '<br>';
echo $redis->hset('d-7','field',5);
echo '<br>';
echo $redis->hset('d-15','field',1);
echo '<br>';
echo $redis->hset('d-23','field',9);
echo '<br>';
echo $redis->hset('d-110','field',3);
echo '<br>';
print_r($redis->sort('sort-input','d-*->field'));
echo '<br>';
print_r($redis->sort('sort-input','d-*->field','d-*->field'));
echo '<br>';
