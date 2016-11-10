[原题](https://leetcode.com/problems/populating-next-right-pointers-in-each-node/)


题意：

对二叉树中的每个节点，添加一个向右的指针，指向每层的右边的一个节点。


想到的当然是bfs，但是题目要求使用的空间必须是常数的。

因此可以每层每层的遍历，当前层next指针的设置，可以依赖上面的那一层进行。


```
# Definition for binary tree with next pointer.
# class TreeLinkNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
#         self.next = None

class Solution:
    # @param root, a tree link node
    # @return nothing
    def connect(self, root):
        pre, head = None, None
        cur = root
        while cur:
            # current level
            while cur:
                if cur.left:
                    if pre: pre.next = cur.left
                    else: head = cur.left
                    pre = cur.left
                
                if cur.right:
                    if pre: pre.next = cur.right
                    else: head = cur.right
                    pre = cur.right
                # move to the next node
                cur = cur.next
            # move to the next level
            cur = head
            pre, head = None, None

```

