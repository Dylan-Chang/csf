<?php
/*
��3-11 Redis�ṩ�ķ����붩������
���� 	����������
SUBSCRIBE 	SUBSCRIBE channel [channel ...]�������ĸ�����һ������Ƶ��
UNSUBSCRIBE 	UNSUBSCRIBE [channel [channel ...]]�����˶�������һ������Ƶ�������ִ��ʱû�и����κ�Ƶ������ô�˶�����Ƶ��
PUBLISH 	PUBLISH channel message���������Ƶ��������Ϣ
PSUBSCRIBE 	PSUBSCRIBE pattern [pattern ...]�������������ģʽ��ƥ�������Ƶ��
PUNSUBSCRIBE 	PUNSUBSCRIBE [pattern [pattern ...]]�����˶�������ģʽ�����ִ��ʱû�и����κ�ģʽ����ô�˶�����ģʽ
*/
function conn_redis(){
	$redis = new redis();
    $redis->connect('127.0.0.1',6379); 
	return $redis;
}

function publisher($n){
	sleep(1);
	foreach($i as range($n)){
		$redis = conn_redis();
		sleep(1);
	}
}

function run_pubsub(){
	//��Ϊ�õ����߳� �ݲ���д
	
}



