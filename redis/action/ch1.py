import time
import unittest

#�����½���ͶƱ
ONE_WEEK_IN_SECONDS = 7 * 86400
VOTE_SCORE = 432 #���������ͨ����һ���������86 400����������չʾһ�������֧��Ʊ������200���ó���

def article_vote(conn, user, article):

    # �������µ�ͶƱ��ֹʱ�䡣
    cutoff = time.time() - ONE_WEEK_IN_SECONDS

    # ����Ƿ񻹿��Զ����½���ͶƱ
    #����Ȼʹ��ɢ��Ҳ���Ի�ȡ���µķ���ʱ�䣬
    # �����򼯺Ϸ��ص����·���ʱ��Ϊ��������
    # ���Բ�����ת��ֱ��ʹ�ã���
    if conn.zscore('time:', article) < cutoff:
        return

    # ��article:id��ʶ����identifier������ȡ�����µ�ID��
    article_id = article.partition(':')[-1]

    # ����û��ǵ�һ��Ϊ��ƪ����ͶƱ����ô������ƪ���µ�ͶƱ���������֡�
    if conn.sadd('voted:' + article_id, user):
        conn.zincrby('score:', article, VOTE_SCORE)
        conn.hincrby(article, 'votes', 1)
# <end id="upvote-code"/>
	  
def post_article(conn, user, title, link):
    # ����һ���µ�����ID��
    article_id = str(conn.incr('article:'))

    voted = 'voted:' + article_id
    # ���������µ��û���ӵ����µ���ͶƱ�û��������棬
    # Ȼ����������Ĺ���ʱ������Ϊһ�ܣ���3�½��Թ���ʱ��������ϸ�Ľ��ܣ���
    conn.sadd(voted, user)
    conn.expire(voted, ONE_WEEK_IN_SECONDS)

    now = time.time()
    article = 'article:' + article_id
    # ��������Ϣ�洢��һ��ɢ�����档
    conn.hmset(article, {
        'title': title,
        'link': link,
        'poster': user,
        'time': now,
        'votes': 1,
    })

    # ��������ӵ����ݷ���ʱ����������򼯺Ϻ͸���������������򼯺����档
    conn.zadd('score:', article, now + VOTE_SCORE)
    conn.zadd('time:', article, now) 

    return article_id

ARTICLES_PER_PAGE = 25

def get_articles(conn,page,order='score:'):
    start = (page-1) * ARTICLES_PER_PAGE
    end = start + ARTICLES_PER_PAGE - 1

    ids = conn.zrevrange(order, start, end)
    articles = []
    for id in ids:
        article_data = conn.hgetall(id)
        article_data['id'] = id
        articles.append(article_data)
        
    return articles

#�����½��з���
def add_remove_groups(conn, article_id, to_add=[], to_remove=[]):
    #�����洢������Ϣ�Ľ���.
    article = 'article:' + article_id
    for group in to_add:
        conn.sadd('group:' + group, article)
    for group in to_remove:
        conn.srem('group:' + group, article)

# �����嵥 1-10
# <start id="fetch-articles-group"/>
def get_group_articles(conn, group, page, order='score:'):
    # Ϊÿ��Ⱥ���ÿ������˳�򶼴���һ������
    key = order + group
    # ����Ƿ����ѻ���������������û�еĻ������ڽ�������
    if not conn.exists(key): 
        # �������ֻ��߷���ʱ�䣬��Ⱥ�����½�������
        conn.zinterstore(key,
            ['group:' + group, order],
            aggregate='max',
        )
        # ��Redis��60����֮���Զ�ɾ��������򼯺ϡ�
        conn.expire(key, 60)
    # ����֮ǰ�����get_articles()���������з�ҳ����ȡ�������ݡ�
    return get_articles(conn, page, key)
# <end id="fetch-articles-group"/>
	  
class TestCh01(unittest.TestCase):
   def setUp(self):
     import redis
     self.conn = redis.Redis(db=15)
	 
   def test_article_functionality(self):
     conn = self.conn
     import pprint
	 
     article_id = str(post_article(conn,'username','A title','www.google.com'));
     print "new article:" + article_id
     print
     self.assertTrue(article_id)

     print "HASH:"
     r = conn.hgetall('article:' + article_id)
     print r
     print
     self.assertTrue(r)

     article_vote(conn, 'other_user','article:' + article_id)
     print "votes:",
     v = int(conn.hget('article:' + article_id,'votes')) 
     print v
     print
     self.assertTrue(v > 1)

     print 'articles ars:'
     articles = get_articles(conn,1)
     pprint.pprint(articles)
     print

     self.assertTrue(len(articles) >= 1)

     add_remove_groups(conn, article_id, ['new-group'])
     print "new group:"
     articles = get_group_articles(conn, 'new-group', 1)
     pprint.pprint(articles)
     print
     self.assertTrue(len(articles) >= 1)

     to_del = (
        conn.keys('time:*') + conn.keys('voted:*') + conn.keys('score:*') +
        conn.keys('article:*') + conn.keys('group:*')
     )
     if to_del:
         conn.delete(*to_del)
	 
if __name__ == '__main__':
    unittest.main()
   

	 
	 
     
