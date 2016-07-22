import time
import unittest

#对文章进行投票
ONE_WEEK_IN_SECONDS = 7 * 86400
VOTE_SCORE = 432 #这个常量是通过将一天的秒数（86 400）除以文章展示一天所需的支持票数量（200）得出的

def article_vote(conn, user, article):

    # 计算文章的投票截止时间。
    cutoff = time.time() - ONE_WEEK_IN_SECONDS

    # 检查是否还可以对文章进行投票
    #（虽然使用散列也可以获取文章的发布时间，
    # 但有序集合返回的文章发布时间为浮点数，
    # 可以不进行转换直接使用）。
    if conn.zscore('time:', article) < cutoff:
        return

    # 从article:id标识符（identifier）里面取出文章的ID。
    article_id = article.partition(':')[-1]

    # 如果用户是第一次为这篇文章投票，那么增加这篇文章的投票数量和评分。
    if conn.sadd('voted:' + article_id, user):
        conn.zincrby('score:', article, VOTE_SCORE)
        conn.hincrby(article, 'votes', 1)
# <end id="upvote-code"/>
	  
def post_article(conn, user, title, link):
    # 生成一个新的文章ID。
    article_id = str(conn.incr('article:'))

    voted = 'voted:' + article_id
    # 将发布文章的用户添加到文章的已投票用户名单里面，
    # 然后将这个名单的过期时间设置为一周（第3章将对过期时间作更详细的介绍）。
    conn.sadd(voted, user)
    conn.expire(voted, ONE_WEEK_IN_SECONDS)

    now = time.time()
    article = 'article:' + article_id
    # 将文章信息存储到一个散列里面。
    conn.hmset(article, {
        'title': title,
        'link': link,
        'poster': user,
        'time': now,
        'votes': 1,
    })

    # 将文章添加到根据发布时间排序的有序集合和根据评分排序的有序集合里面。
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

#对文章进行分组
def add_remove_groups(conn, article_id, to_add=[], to_remove=[]):
    #构建存储文章信息的建名.
    article = 'article:' + article_id
    for group in to_add:
        conn.sadd('group:' + group, article)
    for group in to_remove:
        conn.srem('group:' + group, article)

# 代码清单 1-10
# <start id="fetch-articles-group"/>
def get_group_articles(conn, group, page, order='score:'):
    # 为每个群组的每种排列顺序都创建一个键。
    key = order + group
    # 检查是否有已缓存的排序结果，如果没有的话就现在进行排序。
    if not conn.exists(key): 
        # 根据评分或者发布时间，对群组文章进行排序。
        conn.zinterstore(key,
            ['group:' + group, order],
            aggregate='max',
        )
        # 让Redis在60秒钟之后自动删除这个有序集合。
        conn.expire(key, 60)
    # 调用之前定义的get_articles()函数来进行分页并获取文章数据。
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
   

	 
	 
     
