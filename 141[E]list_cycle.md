[原题](https://leetcode.com/problems/linked-list-cycle/)

题意：

链表是不是有环？

不能使用额外的空间，这个题目使用快慢指针即可。

```
# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def hasCycle(self, head):
        """
        :type head: ListNode
        :rtype: bool
        """
        if not head: return False
        p = head
        q = head.next
        while p and q:
            if q.next and q.next.next:
                p = p.next
                q = q.next.next
            else:
                break
            if p is q:
                return True
        return False
```

