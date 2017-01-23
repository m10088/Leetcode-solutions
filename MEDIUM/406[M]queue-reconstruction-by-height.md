[原题](https://leetcode.com/problems/queue-reconstruction-by-height)

题意:

给定一队人，给出每个人的身高和一个属性（前面比他高的人有几个）。重新排列这一队人。

首先拿到这个题目，想到的是排序，按照身高从高到低排序，身高相同的，按照第二个属性从小到大排序，然后模拟队列的插入即可。

题解:


```Python
class Solution(object):
    def reconstructQueue(self, people):
        """
        :type people: List[List[int]]
        :rtype: List[List[int]]
        """
        def _cmp(first, second):
            if first[0] > second[0]: return -1
            elif first[0] < second[0]: return 1
            elif first[1] < second[1]: return -1
            elif first[1] > second[1]: return 1
            else: return 0
        
        people = sorted(people, cmp=_cmp)
        
        res = []
        for p in people:
            res.insert(p[1], p)
        
        return res
```
