[原题](https://leetcode.com/problems/copy-list-with-random-pointer)

题意：

题解：

```
# Definition for singly-linked list with a random pointer.
# class RandomListNode(object):
#     def __init__(self, x):
#         self.label = x
#         self.next = None
#         self.random = None

class Solution(object):

    def copyRandomList(self, head):
        """
        :type head: RandomListNode
        :rtype: RandomListNode
        """
        mp = dict()
        def dfs(head):
            if not head: return None
            if head in mp: return mp[head]
            cphead = RandomListNode(head.label)
            mp[head] = cphead 
            cphead.next = dfs(head.next)
            cphead.random = dfs(head.random)
            return cphead
        return dfs(head)
        
```