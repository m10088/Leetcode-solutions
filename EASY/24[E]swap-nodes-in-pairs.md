[原题](https://leetcode.com/problems/swap-nodes-in-pairs/)

题意：

交换链表上两个相邻的点。

注意一下，奇数个点的时候的情况即可。

```Python
# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def swapPairs(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        if not head: return head
        nummy = ListNode(-1)
        nummy.next = head
        q = nummy
        p = nummy.next
        while p:
            
            if not p.next:
                break
            two = p.next
            back_next = two.next
            q.next = two
            p.next = back_next
            two.next = p
            
            q = p
            p = back_next
        
        return nummy.next
```