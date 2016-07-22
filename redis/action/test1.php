<?php
 //组装操作日志内容 end -- zhaijianwen 20150814
      	                $createCouponData = array(
      	                    'subject'   => $bat['subject'],
      	                    'quantity'  => $bat['quantity'], 
      	                    'facevalue' => $bat['facevalue'], 
      	                    'p_id'      => $p_id, 
      	                    'c_id'      => $c_id, 
      	                    'catid'     => $catid, 
      	                    'kssj'      => $bat['kssj'], 
      	                    'dqsj'      => $bat['dqsj'],
      	                    'slhqz'     => $other['slhqz'],
      	                    'mode'      => $bat['mode']
      	                );
      	                $this->redis = getRedis();
      	                $this->redis->lpush('coupon_waitcreate_list', json_encode($createCouponData));
      	                $msg = '添加红包成功！';
						
						