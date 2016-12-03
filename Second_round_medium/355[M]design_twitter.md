[原题](https://leetcode.com/problems/design-twitter/)

题意：

数据结构设计，仿照推特，可以发布文章，关注某个人，取消关注某个人，如果刷新，那么将得到关注的列表按照时间排序的前10个人的文章。

这个题目的坑大概有：

1.自己永远是关注自己的，取消关注也不行。
2.如果使用python可能报各种，keyError，大概就是，很多值和哈希表中没有初始化。我为了避免这一点，设计了一个辅助的函数，用于消除这一个现象。
3.注意，推文和关注的人，不能重复了。


```
class Twitter(object):

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.follow_who = dict()
        self.timer = 0
        self.twitters = dict()
    
    def add_user_if_need(self, userId):
        if userId not in self.twitters:
            self.twitters[userId] = []
            self.follow_who[userId] = set()
        
    def postTweet(self, userId, tweetId):
        """
        Compose a new tweet.
        :type userId: int
        :type tweetId: int
        :rtype: void
        """
        self.add_user_if_need(userId)
        self.timer += 1
        self.twitters[userId].append((tweetId, self.timer))
        
        
    def getNewsFeed(self, userId):
        """
        Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent.
        :type userId: int
        :rtype: List[int]
        """
        self.add_user_if_need(userId)
        all_twitters = []
        
        # any time you can recieve you self
        for tw in self.twitters[userId]:
            all_twitters.append(tw)
        
        for followeeId in self.follow_who[userId]:
            if followeeId == userId:continue
            for tw in self.twitters[followeeId]:
                all_twitters.append(tw)
        all_twitters = sorted(all_twitters, key=lambda x: x[1], reverse=True)
        return [x[0] for x in all_twitters[:10]]
        
    def follow(self, followerId, followeeId):
        self.add_user_if_need(followerId)
        self.add_user_if_need(followeeId) 
        """
        Follower follows a followee. If the operation is invalid, it should be a no-op.
        :type followerId: int
        :type followeeId: int
        :rtype: void
        """
        if followerId not in self.follow_who: self.follow_who[followerId] = set([followeeId])
        else: self.follow_who[followerId].add(followeeId)
        
    def unfollow(self, followerId, followeeId):
        self.add_user_if_need(followerId)
        self.add_user_if_need(followeeId) 
        """
        Follower unfollows a followee. If the operation is invalid, it should be a no-op.
        :type followerId: int
        :type followeeId: int
        :rtype: void
        """
        try:
            self.follow_who[followerId].remove(followeeId)
        except:
            pass

# Your Twitter object will be instantiated and called as such:
# obj = Twitter()
# obj.postTweet(userId,tweetId)
# param_2 = obj.getNewsFeed(userId)
# obj.follow(followerId,followeeId)
# obj.unfollow(followerId,followeeId)
```