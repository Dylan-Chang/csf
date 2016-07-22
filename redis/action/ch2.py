import json
import threading
import time
import unittest
import urlparse
import uuid

def check_token(conn, token):
  return conn.hget('login:', token) # ���Ի�ȡ���������ƶ�Ӧ���û���

def update_token(conn, token, user, item):
  timestamp = time.time()
  conn.hset('login:', token, timestamp)
  conn.zadd('recent:', token, timestamp)
  if item:
    # ��¼�û����������Ʒ��
    conn.zadd('viewed:' + token, item, timestamp)
    # �Ƴ��ɵļ�¼��ֻ�����û�����������25����Ʒ��
    conn.zremrangebyrank('viewed:' + token, 0, -26)

def clean_sessions(conn):
  # �ҳ�Ŀǰ�������Ƶ�������

class TestCh02(unittest.TestCase):
  def setUp(self):
    import redis
    self.conn = redis.Redis(db=15)

  def test_login_cookies(self):
      conn = self.conn
      global LIMIT, QUIT
      token = str(uuid.uuid4())

      update_token(conn, token, 'username', 'itemX')
      print "updated token:", token
      print

      print "token"
      r = check_token(conn, token)
      print r
      print
      self.assertTrue(r)

      LIMIT = 0
      t = threading.Thread(target=clean_sessions, args=(conn,))
      t.setDaemon(1)
      t.start()
      time.sleep(1)
      QUIT = True
      time.sleep(2)
      if t.isAlive():
          raise Exception("?!?")

      s = conn.hlen('login:')
      print 'sessions:'.s
      self.assertFalse(s)
      
      
if __name__ == '__main__':
    unittest.main()
    
