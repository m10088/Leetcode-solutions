[原题](https://leetcode.com/problems/merge-two-sorted-lists/)

题意：

合并两个有序链表：


```Python
# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def mergeTwoLists(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        nummy = ListNode(-1)
        p = nummy
        while True:
                if not l1 and not l2:
                    break
                if l1 and l2 and l1.val <= l2.val or not l2:
                    
                    tmp = l1
                    l1 = l1.next
                    p.next = tmp
                    p = p.next
                    
                elif l1 and l2 and l1.val > l2.val or not l1:
                    
                    tmp = l2
                    l2 = l2.next
                    p.next = tmp
                    p = p.next
                    
                
        return nummy.next
```