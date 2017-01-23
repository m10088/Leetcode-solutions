[原题](https://leetcode.com/problems/partition-list/)


题意：


链表切分，小于x的放一边，大于x的放一边。

```Python
# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None


class Solution(object):
    def partition(self, head, x):
        """
        :type head: ListNode
        :type x: int
        :rtype: ListNode
        """
        # >= -> move to the tail, others -> original position
        # nummy, origin dummy new
        nummy, dummy = ListNode(-1), ListNode(-2)
        nummy.next, cur = head, dummy
        q, p = nummy, head
        while p:
            if p.val < x:
                q, p = p, p.next
            else:
                cur.next = p
                cur = cur.next
                
                p = p.next
                q.next = p
        # attention! 
        cur.next = None
        q.next = dummy.next
        return nummy.next
```