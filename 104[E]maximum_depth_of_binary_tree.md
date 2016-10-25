[原题](https://leetcode.com/problems/maximum-depth-of-binary-tree/)

题意求二叉树的最大的高度：

```
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def maxDepth(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        if not root:
            return 0
        else:
            return max(self.maxDepth(root.right), self.maxDepth(root.left)) + 1
        
```