[原题](https://leetcode.com/problems/house-robber-iii)

题意:

house robber的升级版，这次是在一个二叉树上，条件类似，就是不能有相邻的节点是同时偷的。

因此这里，需要对树的节点进行两个hash。


题解:


```
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def rob(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        # 两个--hash--，偷这个树的根节点和不偷这个树的根节点的最大的值是多少
        mp0, mp1 = dict(), dict()
        
        def dfs0(root):
            if not root: return 0
            if root in mp0: return mp0[root]
            tmpleft = max(dfs0(root.left), dfs1(root.left))
            tmpright = max(dfs0(root.right), dfs1(root.right))
            mp0[root] = tmpleft + tmpright
            return mp0[root]
            
        def dfs1(root):
            if not root: return 0
            if root in mp1: return mp1[root]
            tmp = dfs0(root.left) + dfs0(root.right) + root.val
            mp1[root] = tmp
            return tmp
        
        return max(dfs0(root), dfs1(root))
```
