[原题](https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/)


题意：

将一个升序的数组，转化成平衡的BST。

```Python
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def sortedArrayToBST(self, nums):
        """
        :type nums: List[int]
        :rtype: TreeNode
        """
        if len(nums) == 0: return None
        sel = len(nums) // 2
        ret = TreeNode(nums[sel])
        ret.left, ret.right = self.sortedArrayToBST(nums[:sel]), self.sortedArrayToBST(nums[sel+1:])
        return ret
```