[原题](https://leetcode.com/problems/flatten-binary-tree-to-linked-list/)


题意：


Given a binary tree, flatten it to a linked list in-place.


之前也是没有思路，其实解法已经在hint中给出了。

If you notice carefully in the flattened tree, each node's right child points to the next node of a pre-order traversal.


```Python
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    
    def __init__(self):
        self.prev = None
    def flatten(self, root):
        """
        :type root: TreeNode
        :rtype: void Do not return anything, modify root in-place instead.
        """
    
        if not root: return
        self.flatten(root.right);
        self.flatten(root.left);
        root.right = self.prev;
        root.left = None;
        self.prev = root;
```

这里采用了后续遍历的方式解决，而没有使用先序遍历，因为先序遍历的next就是后序遍历的pre。

