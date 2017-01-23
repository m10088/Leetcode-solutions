[原题](https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/)

题意：

二叉树的最小公共祖先。

如果套用235的方法，TLE。

现在看来这种方法是相当naive的。

235的方法：从顶向下dfs，每个节点判断是不是一个，lca。


```Python
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def has_child(self, root, child):
        if root is None:
            return False
        if root is child:
            return True
        return self.has_child(root.left, child) or self.has_child(root.right, child)
        
    def lowestCommonAncestor(self, root, p, q):
        """
        :type root: TreeNode
        :type p: TreeNode
        :type q: TreeNode
        :rtype: TreeNode
        """
        
        if self.has_child(root.left, p) and self.has_child(root.left, q):
            return self.lowestCommonAncestor(root.left, p, q)
        if self.has_child(root.right, p) and self.has_child(root.right, q):
            return self.lowestCommonAncestor(root.right, p, q)
        return root
        
```

改进策略：

```Python
def lowestCommonAncestor(self, root, p, q):
        """
        :type root: TreeNode
        :type p: TreeNode
        :type q: TreeNode
        :rtype: TreeNode
        """
        if not root or root == p or root == q: return root
        tmp1 = self.lowestCommonAncestor(root.left, p, q)
        tmp2 = self.lowestCommonAncestor(root.right, p, q)
        if not tmp1: return tmp2
        if not tmp2: return tmp1
        return root
```

假如说，q和p都不在所寻找的子树内部，那么返回的是None.
假如说，两个子树返回的结果都不是None，那么p和q一定分别在左右子树中，因此返回的是root。


这里还有一种迭代的解决方案，就是先通过遍历一遍，找到每个节点的parent节点，hash存放好，然后，通过遍历从p到节点的路径，将p的祖先提取出来，放到一个set中，然后，我们遍历从q到节点的路径，第一个在set中出现的那个就是LCA。

当然这里的遍历可以使用stack尽心模拟实现。

```Python
def lowestCommonAncestor(self, root, p, q):
        def dfs(root, parents, pre):
            if root:
                parents[root] = pre
                dfs(root.left, parents, root), dfs(root.right, parents, root)
        parents = dict()
        dfs(root, parents, None)
        ancestor = set()
        while p:
            ancestor.add(p)
            p = parents[p]
        while q not in ancestor:
            q = parents[q]
        return q
```
