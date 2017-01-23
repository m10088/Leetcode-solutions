[原题](https://leetcode.com/problems/count-complete-tree-nodes/)


题意：

给定完全二叉树（最后一行是从左向右排布的）。

统计数的大小。

暴力的O（n）级别是不行的。

一定会用到二叉树的性质。


因此，先看一颗树是不是完全二叉树，条件就是左右的深度完全相同。


如果不是才采用原始的递归的方式进行。

算法的复杂度是

O(log(n)^2).


```Python
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def countNodes(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        
       
        
        def count_side(root, flag):
            cnt, tmp = 0, root
            while tmp:
                tmp = tmp.left if flag else tmp.right
                cnt += 1
            return cnt
        
        def count_depth_equal(root):
            left, right = count_side(root, 1), count_side(root, 0)
            if left == right: return left
            else: return -1
        
        res = count_depth_equal(root)
        if res != -1: return 2 ** res - 1
        else: return 1 + self.countNodes(root.left) + self.countNodes(root.right)
        
        
        
        
```