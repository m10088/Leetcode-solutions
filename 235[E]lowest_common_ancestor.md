[原题]()

题意：

一颗二叉搜索树的最小公共祖先。


这种解法，没有使用到二叉搜索树的性质，复杂度较高。

```
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



另一种解法，考虑二叉搜索树的性质。
先让查找的p和q的大小关系固定，p<q
然后，如果p和q都小于根，那么在左边的子树中找，如果p和q都大于根，那么在右边的子树中找，如果，有一个等于，那么返回这个子树即可。

下面方法，使用了迭代优化。

```
class Solution(object):
    def lowestCommonAncestor(self,root,p,q):
        if p.val>q.val:
            return self.lowestCommonAncestor(root,q,p)
        while not p.val<=root.val<=q.val:
            root=root.left if q.val<root.val else root.right
        return root
```

