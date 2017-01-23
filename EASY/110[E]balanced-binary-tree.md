[原题](https://leetcode.com/problems/balanced-binary-tree/)

题意：

判断一颗树是不是平衡二叉树：

每个节点左右孩子的高度只差不大于1。

clean solution

```Python
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    
    def height(self,root):
        if not root: return 0
        return 1 + max(self.height(root.left), self.height(root.right))
    
    def isBalanced(self, root):
        """
        :type root: TreeNode
        :rtype: bool
        """
        if not root: return True
        if abs(self.height(root.left) - self.height(root.right)) > 1: return False
        return self.isBalanced(root.left) and self.isBalanced(root.right)
```


