[原题](https://leetcode.com/problems/reverse-linked-list-ii/)

题意：

反转给定范围之内的链表。


首先找到范围两边的指针，

如

1,2,3,4,5

反转2-->4，那么分别有

```
prem->1
pm->2
pren->4,
pn->5
```

适当修改```reverse```函数，同时返回结尾的指针。


```
# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

def reverse(head):
    pre = None
    p = head
    while p:
        tmp = p.next
        p.next = pre
        pre = p
        p = tmp
    return pre, head

class Solution(object):
    def reverseBetween(self, head, m, n):
        """
        :type head: ListNode
        :type m: int
        :type n: int
        :rtype: ListNode
        """
        if not head or n - m == 0: return head
        
        # we should make segment out of the linklist
        nummy = ListNode(-1)
        nummy.next = head
        cnt, q, p = 0, nummy, head
        while cnt < m - 1:
            q, p, cnt = p, p.next, cnt + 1
        prem, pm = q, p
        while cnt < n:
            q, p, cnt = p, p.next, cnt + 1
        pren, pn = q, p
        
        
        
        pren.next = None
        after_head, after_tail = reverse(pm)
        prem.next = after_head
        after_tail.next = pn
        
        return nummy.next
        
        
        

```