[原题](https://leetcode.com/problems/odd-even-linked-list/)

题意：

类似【143】的逆过程，细节较多。

```Python
# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def oddEvenList(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        # nummy origin, dummy new
        if not head : return head
        nummy, dummy = ListNode(-1), ListNode(-1)
        nummy.next = head
        # restore the result
        cur = dummy
        pre, p = nummy, nummy.next
        while p:
            q, p = p, p.next
            # pay attention to here!
            if not p: break
            tmp_p_next = p.next
            
            cur.next = p
            cur = cur.next
            
            p = tmp_p_next
            q.next = p
        # had to teminate the second linklist
        cur.next = None
        q.next = dummy.next
        return nummy.next
```
