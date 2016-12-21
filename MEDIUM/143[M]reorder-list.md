[原题](https://leetcode.com/problems/reorder-list/)

题意：

Given a singly linked list L: L0→L1→…→Ln-1→Ln,
reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…

1,2,3,4,5 -> 1,5,3,4,2


正确的使用partataion和reverse函数。

```
# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

# partation this linklist into 2 parts 1, 2, 3, 4, 5 -> 1, 2, 3 | 4, 5, return pointer to 4

def partation(head):
    # split the list into two part and reverse last part then compare with each other
    p = head
    q = head
    while q:
        if q.next:
            q = q.next
        else:
            break
        if q.next:
            q = q.next
        else:
            break
        # think why we do this here ?
        p = p.next
    ret = p.next
    p.next = None
    return ret

# reverse linklist 
def reverse(head):
    pre = None
    p = head
    while p:
        tmp = p.next
        p.next = pre
        pre = p
        p = tmp
    return pre

class Solution(object):
    def reorderList(self, head):
        """
        :type head: ListNode
        :rtype: void Do not return anything, modify head in-place instead.
        """
        if not head or not head.next: return
        mid = reverse(partation(head))
        nummy = ListNode(-1)
        nummy.next = head
        # cur point to the node which will be add to the linklist next
        cur = mid
        q, p = nummy, head
        
        while p:
            q, p = p, p.next
            if not cur:
                break
            tmp_cur_next = cur.next
            q.next = cur
            cur.next = p
            
            cur = tmp_cur_next
            
            q = q.next
        head = nummy.next     
```