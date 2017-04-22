[原题](https://leetcode.com/problems/reverse-nodes-in-k-group)

题意

题解

```Python
# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

def printList(head):
    p = head
    while p:
        print p.val
        p = p.next
    

class Solution(object):
    def reverseKGroup(self, head, k):
        """
        :type head: ListNode
        :type k: int
        :rtype: ListNode
        """
        if not head or k < 2: return head
        def reverse(head):
            p, pre = head, None
            while p:
                tmp = p.next
                p.next = pre
                pre = p
                p = tmp
            return pre
        # 最后用于拼接使用
        group, rec = [], head
        p, pre, cnt = head, None, 0
        while p:
            cnt += 1
            q = p
            p = p.next
            if cnt % k == 0: # 到达了分割点的位置
                q.next = None
                group.append(reverse(rec))
                rec = p
        # 将group的内容全部连接起来，然后最后加上rec
        dummy = ListNode(-1)
        p = dummy
        for linklist in group:
            p.next = linklist
            while p.next:
                p = p.next
        p.next = rec
        return dummy.next
        
            
        
        
        
        
```