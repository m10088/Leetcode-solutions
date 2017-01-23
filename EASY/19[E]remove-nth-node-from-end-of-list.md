[原题](https://leetcode.com/problems/remove-nth-node-from-end-of-list/)

题意：

删除从尾部开始往前数的第n个节点。

题目要求是one pass， 一时没想到好的方法，提示是双指针，讨论区有一种很好的方法，用2个指针，先用一个指针走n个位置，然后第二个指针与第一个指针一起走，直到第一个指针为null，此时第二个指针就是要删除的节点的前一个节点。

注意：删除的节点可能是head。

```Python
# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def removeNthFromEnd(self, head, n):
        """
        :type head: ListNode
        :type n: int
        :rtype: ListNode
        """
        p, q = head, head
        for _ in range(n):
            p = p.next
        
        # in case that the target is head
        if not p:
            return head.next
        
        while p.next:
            p = p.next
            q = q.next
        q.next = q.next.next
        
        return head
```

[提供一种递归的思路](http://blog.csdn.net/guicaisa/article/details/52156692)
