[原题](https://leetcode.com/problems/delete-node-in-a-linked-list/)

题意：

给定链表的一个入口，要求删除这个节点。


因为给定的节点不会是尾部的节点，因此可以删除下一个节点，将下一个节点的内容，放到本节点即可。

```Python
# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def deleteNode(self, node):
        """
        :type node: ListNode
        :rtype: void Do not return anything, modify node in-place instead.
        """
        tmp = node.next
        node.val = tmp.val
        node.next = tmp.next
        
```