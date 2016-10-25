[原题](https://leetcode.com/problems/minimum-depth-of-binary-tree/)

二叉树中到根的长度最小一个叶子节点。

不能直接修改最长叶子节点那个算法的max为min，出错。

两种方法：

直接遍历，遍历的时候，如果到大叶子节点，更新，当前的最小的值。

```
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def __init__(self):
        self.ret = float("inf")
    
    def dfs(self, root, depth):
        if not root.left and not root.right:
            self.ret = min(self.ret, depth)
        if root.left:
            self.dfs(root.left, depth+1)
        if root.right:
            self.dfs(root.right, depth+1)
    
    def minDepth(self, root, depth=1):
        """
        :type root: TreeNode
        :rtype: int
        """
        self.ret = float("inf")
        if not root:
            return 0
        self.dfs(root, 1)
        return self.ret
```

另外一种递归方法：

```
def minDepth(self, root):
    if not root:
        return 0
    if not root.left or not root.right:
        return max(self.minDepth(root.left), self.minDepth(root.right)) + 1
    else:
        return min(self.minDepth(root.left), self.minDepth(root.right)) + 1
```


