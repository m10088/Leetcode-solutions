[原题](https://leetcode.com/problems/remove-duplicates-from-sorted-list/)

题意：

删除排序的链表中重复的元素：


增加一个空余的节点

```Python

# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def deleteDuplicates(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        have_seen = set()
        nummy = ListNode(-1)
        nummy.next = head
        q, p = nummy, nummy.next
        while p:
            if p.val in have_seen:
                q.next = p.next
                p = p.next
            else:
                have_seen.add(p.val)
                q, p = p, p.next
                
        return nummy.next
```