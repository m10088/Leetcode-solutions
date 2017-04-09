[原题](https://leetcode.com/problems/merge-k-sorted-lists)

题意

题解

```
# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

import Queue
class Solution(object):
    def mergeKLists(self, lists):
        """
        :type lists: List[ListNode]
        :rtype: ListNode
        """
        dummy = ListNode(-1)
        p = dummy
        pq = Queue.PriorityQueue()
        for node in lists:
            if node: #列表中的元素可能一开始不存在
                pq.put((node.val, node))
        while pq.empty() == False:
            fro = pq.get()
            p.next = fro[1]
            p = p.next
            if fro[1].next: 
                pq.put((fro[1].next.val, fro[1].next))
        p.next = None
        return dummy.next
        
        
```