[原题](https://leetcode.com/problems/sum-root-to-leaf-numbers/)

题意：

树每个节点，代表数字，然后从根节点到叶子节点，排成的数字组成一个数，求这些数的和。

python递归过程修改局部全局变量，不是很方便，但是一般的int变量不能传递引用，使用list封装了下。

```
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def sumNumbers(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        if not root: return 0
        ret = [0] #golbal_val
        def dfs(root, last, lister):
            val = last * 10 + root.val
            if not root.left and not root.right: 
                ret[0] += val
            else:
                if root.left: dfs(root.left, val, lister)
                if root.right: dfs(root.right, val, lister)
        
        dfs(root, 0, ret)
        return ret[0]
```