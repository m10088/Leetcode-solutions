[原题](https://leetcode.com/problems/reverse-linked-list/)

题意：

反转链表。


```Python
# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def reverseList(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        
        pre = None
        p = head
        while p:
            tmp = p.next
            p.next = pre
            pre = p
            p = tmp
        return pre
        
        
```