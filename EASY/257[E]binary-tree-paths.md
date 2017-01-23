[原题](https://leetcode.com/problems/binary-tree-paths/)

题意：

二叉树的路径。


遍历的同时记录即可，注意python的list的 = 并不是复制。

```Python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def __init__(self):
        self.ret = []
    # @param {TreeNode} root
    # @return {string[]}
    def binaryTreePaths(self, root):
        def dfs(root, lister):
            newlist = lister[:]
            newlist.append(root.val)
            if not root.left and not root.right:
                self.ret.append(newlist)
            if root.left:
                dfs(root.left, newlist)
            if root.right:
                dfs(root.right, newlist)
        if not root: return []
        dfs(root, [])
        return list(set(['->'.join([str(char) for char in x]) for x in self.ret]))
            
```
