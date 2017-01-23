[原题](https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/)

题意：

给定一个中序遍历和后续遍历的数组，还原整棵二叉树。


递归过程的几个参数：

中序遍历数组的开始和结尾，后续遍历数组的开始和结尾。

Then code tells everything.

```Python
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def buildTree(self, inorder, postorder):
        """
        :type inorder: List[int]
        :type postorder: List[int]
        :rtype: TreeNode
        """
        def get_index(li, target):
            for i, val in enumerate(li):
                if val == target:
                    return i
        
        if not inorder: return None
        # close [] intervals
        def get_root(inl, inr, postl, postr):
            if inl > inr:
                return None
            # the root position in inoderlist
            piv = get_index(inorder, postorder[postr])
            # the number of left-subtree and the right-subtree
            ln, rn = piv - inl, inr - piv
            # creat a new tree recursively
            root = TreeNode(postorder[postr])
            root.left = get_root(inl, piv-1, postl, postl + ln - 1) 
            root.right = get_root(piv+1, inr, postl + ln, postr - 1)
            return root
        n = len(inorder)
        return get_root(0, n-1, 0, n-1)
    
            
            
```