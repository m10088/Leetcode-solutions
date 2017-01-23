[原题](https://leetcode.com/problems/insertion-sort-list/)

题意：

链表的插入排序，没有什么技巧，完全是细节。

题解：

```Python
# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def insertionSortList(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        if not head: return head
        retnummy = ListNode(-1)
        nummy = ListNode(-2)
        nummy.next = head
        
        p = head
        while p:
            tmp_next = p.next
            pre, cur = retnummy, retnummy.next
            while cur:
                if cur.val > p.val:
                    break
                else:
                    pre = cur
                    cur = cur.next
                
            pre.next = p
            p.next = cur
            p = tmp_next
    
        return retnummy.next
```