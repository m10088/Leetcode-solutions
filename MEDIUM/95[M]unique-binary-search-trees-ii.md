[原题](https://leetcode.com/problems/unique-binary-search-trees-ii/)


题意：

给定一个数字n，要求所有的1-n的BST的集合。


递归的思想，考虑1-n中的任意一个数字k，左边的集合是1~k-1的所有的可能的情况，右边集合是k+1~n左右的可能情况，将第k个数字作为根，两边的元素进行简单的组合一下即可。


```
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def generateTrees(self, n):
        """
        :type n: int
        :rtype: List[TreeNode]
        """
        if n == 0: return []
        return list(self.fx(1, n))
        
    def fx(self, a, b): # [intervals]
        if a > b: return set([None])
        ret = set()
        for i in range(a, b+1):
            left_set = self.fx(a, i-1)
            right_set = self.fx(i+1, b)
            
            for left_sub in left_set:
                for right_sub in right_set:
                    root = TreeNode(i)
                    root.left, root.right = left_sub, right_sub
                    ret.add(root)
        return ret
        

```