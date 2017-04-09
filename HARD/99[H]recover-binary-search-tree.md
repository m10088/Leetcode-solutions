[原题](https://leetcode.com/problems/recover-binary-search-tree)

题意

题解

```
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def recoverTree(self, root):
        """
        :type root: TreeNode
        :rtype: void Do not return anything, modify root in-place instead.
        """
        # 目的是在中序遍历的过程中找出小于前面的那个值的数字所在的指针
        pre = [None]
        wrong = []
        def dfs(root):
            if root:
                dfs(root.left)
                if pre[0] and root.val < pre[0].val:
                    wrong.append((pre[0], root))
                pre[0] = root
                print root.val
                dfs(root.right)
            
        dfs(root)
        a, b = None, None
        # 这里分为两种情况，可能交换的两个元素是相邻的，也可能是不相邻的
        if len(wrong) == 1: # 相邻
            a, b = wrong[0][0], wrong[0][1]
        elif len(wrong) == 2: # 不相邻
            a, b = wrong[0][0], wrong[1][1]
        else:
            pass
        if a and b:
            a.val, b.val = b.val, a.val
        
        
        
```