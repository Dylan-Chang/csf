<?php
$redis = new redis();
//ʵ�����ӵ�һ��Redis.
$redis->connect('127.0.0.1',6379);
//����key��value��ֵ
$redis->set('test','111111111');
//��ȡ�й�ָ������ֵ
$result = $redis->get('test');
//ɾ��ָ���ļ�
$redis->delete('test');
//��������ݿ��в����ڸü������ùؼ�ֵ����
$redis->setnx('test','2222222');
//��ָ֤���ļ��Ƿ����
$redis->existe('test');
//���ֵ����洢��ֵ��
var_dump($redis->incr('test'));
var_dump($redis->incr('test'));
//���ֵݼ��洢��ֵ
var_dump($redis->decr('test'));
var_dump($redis->decr('test'));
//ȡ������ָ������ֵ�����һ�������������ڣ��������иü���ֵΪ��
$redis->set('test1','123');
$redis->set('test2','456');
$redis->getMultiple(array('test1','test2'));

var_dump($result);