[原题](https://leetcode.com/problems/validate-binary-search-tree/)

题意：

当然是可是使用中序遍历之后，然后判断是不是递增的。

但是这里我们使用简洁的dfs实现。

```
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def isValidBST(self, root, miner = -float('inf'), maxer = float('inf')):
        """
        :type root: TreeNode
        :rtype: bool
        """
        if not root: return True
        if miner < root.val < maxer:
            return self.isValidBST(root.left, miner, root.val) and self.isValidBST(root.right, root.val, maxer)
        else:
            return False
```