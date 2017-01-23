[原题](https://leetcode.com/problems/sum-of-left-leaves/)

题意：

求一颗二叉树的左边的叶子节点的和。


需要额外的添加一个标志，是左边叶子，还是右边的叶子。


```Python
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def sumOfLeftLeaves(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
    
        return self.aid_with_dir(root, 1)
    
    def aid_with_dir(self, tree, dir):
        if not tree:
            return 0
        if not tree.left and not tree.right:
            if dir == 0:
                return tree.val
            else:
                return 0
        else:
            return self.aid_with_dir(tree.left, 0) + self.aid_with_dir(tree.right, 1)
        
```
