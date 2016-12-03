[原题](https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/)


题意：

前序和中序构造二叉树。

自己是沿用了106的解法，但是看了别人的解答，发现自己的代码还是不够简洁啊。


```
def buildTree(self, preorder, inorder):
    if inorder:
        ind = inorder.index(preorder.pop(0))
        root = TreeNode(inorder[ind])
        root.left = self.buildTree(preorder, inorder[0:ind])
        root.right = self.buildTree(preorder, inorder[ind+1:])
        return root
```


自己的


```
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def buildTree(self, preorder, inorder):
        """
        :type preorder: List[int]
        :type inorder: List[int]
        :rtype: TreeNode
        """
        def get_index(li, target):
            for i, val in enumerate(li):
                if val == target:
                    return i
        
        if not inorder: return None
        # close [] intervals
        def get_root(inl, inr, prel, prer):
            if inl > inr:
                return None
            # the root position in inoderlist
            piv = get_index(inorder, preorder[prel])
            # the number of left-subtree and the right-subtree
            ln, rn = piv - inl, inr - piv
            # creat a new tree recursively
            root = TreeNode(preorder[prel])
            root.left = get_root(inl, piv-1, prel+1, prel + ln - 1) 
            root.right = get_root(piv+1, inr, prel + ln + 1, prer)
            return root
        n = len(inorder)
        return get_root(0, n-1, 0, n-1)
        

```