[原题](https://leetcode.com/problems/rotate-list/)

题意：


旋转数组.

[1,2,3,4,5,6,7] ，3 

那么旋转到[5,6,7,1,2,3,4].


思路：

求余，找到分割点，按步骤设置，head和tail即可。

```Python
# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def rotateRight(self, head, k):
        """
        :type head: ListNode
        :type k: int
        :rtype: ListNode
        """
        if not head: return head
        def getlenth(head):
            cnt, p = 0, head
            while p: p, cnt = p.next, cnt + 1
            return cnt
        lenth = getlenth(head)
        if lenth < 2: return head
        k = k % lenth
        
        # move lenth - k step
        nummy, cnt = ListNode(-1), 0
        nummy.next = head
        q, p = nummy, nummy.next
        while cnt < lenth - k: cnt, q, p = cnt + 1, p, p.next
        
        # set up the head
        save_head = nummy.next
        nummy.next = p
        
        # get_the_origin_tail
        def get_tail(nummy):
            p = nummy
            while p.next: p = p.next
            return p
        
        # set up the tail
        q.next = None
        get_tail(nummy).next = save_head
        
        return  nummy.next
        
```