[原题](https://leetcode.com/problems/binary-tree-right-side-view/)

题意：

从二叉树的最右边看过去，从上往下的数值分别是什么？

这里不使用传统的bfs的方法，采用dfs进行。


```

# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def rightSideView(self, root):
        """
        :type root: TreeNode
        :rtype: List[int]
        """
        def dfs(lister, root, depth):
            if not root: return
            if len(lister) == depth:
                lister.append(root.val)
            dfs(lister, root.right, depth+1)
            dfs(lister, root.left, depth+1)
        
        ret = []
        dfs(ret, root, 0)
        return ret

```