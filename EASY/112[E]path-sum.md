[原题](https://leetcode.com/problems/path-sum/)

题意：

是否存在从叶子到根的路径和为sum的路径。


递归遍历，然后到叶子节点判断。

```Python
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    
    def dfs(self, root, now, sum):
        now += root.val
        if not root.left and not root.right:
            return sum == now
        elif not root.left and root.right:
            return self.dfs(root.right, now, sum)
        elif not root.right and root.left:
            return self.dfs(root.left, now, sum)
        else:
            return self.dfs(root.left, now, sum) or self.dfs(root.right, now, sum)
    
    def hasPathSum(self, root, sum):
        """
        :type root: TreeNode
        :type sum: int
        :rtype: bool
        """
        if not root: return False
        return self.dfs(root, 0, sum)
```

一种递归的解法：

clean solution
```Python
def hasPathSum(self, root, sum):
        if root == None:return False
        if root.val - sum == 0 and root.left == None and root.right == None:return True
        return self.hasPathSum(root.left, sum-root.val) or self.hasPathSum(root.right, sum-root.val)
```
