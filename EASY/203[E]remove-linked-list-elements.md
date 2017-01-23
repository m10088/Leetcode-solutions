[原题](https://leetcode.com/problems/remove-linked-list-elements/)

题意：

给定链表，删除链表中给定的值。

```Python
# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def removeElements(self, head, val):
        """
        :type head: ListNode
        :type val: int
        :rtype: ListNode
        """
        nummy = ListNode(-1)
        nummy.next = head
        q = nummy
        p = nummy.next
        while p:
            if p.val == val:
                q.next = p.next
                p = q.next
            else:
                q = p
                p = p.next
        return nummy.next
```