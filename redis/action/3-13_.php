<?php
/*
表3-13 用于处理过期时间的Redis命令
命令 	示例和描述
PERSIST 	PERSIST key-name——移除键的过期时间
TTL 	TTL key-name——返回给定键距离过期还有多少秒
EXPIRE 	EXPIRE key-name seconds——让键key-name在给定的seconds秒之后过期
EXPIREAT 	EXPIREAT key-name timestamp——将给定键的过期时间设置为给定的UNIX时间戳
PTTL 	PTTL key-name——返回给定键距离过期时间还有多少毫秒，这个命令在Redis 2.6或以上版本可用
PEXPIRE 	PEXPIRE key-name milliseconds——让键key-name在milliseconds毫秒之后过期，这个命令在Redis 2.6或以上版本可用
PEXPIREAT 	PEXPIREAT key-name timestamp-milliseconds——将一个毫秒级精度的UNIX时间戳设置为给定键的过期时间，这个命令在Redis 2.6或以上版本可用
*/

