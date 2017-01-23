[原题](https://leetcode.com/problems/path-sum-ii/)

题意：

求二叉树的路径之和为target的数组。

注意python复制数组可以 ```new = old[:]```。

```Python
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None


def dfs(root, already, target, ret):
        # print 'now', root.val, 'is', sum(already)
        assert root != None
        already.append(root.val)
        if not root.left and not root.right:
            if sum(already) == target:
                ret.append(already)
            else:
                return
        if root.left:
            tmp_already = already[:]
            dfs(root.left, tmp_already, target, ret)
        if root.right:
            temp_already = already[:]
            dfs(root.right, temp_already, target, ret)

    

class Solution(object):
    def __init(self):
        self.ret = []
    
    
    def pathSum(self, root, sum):
        """
        :type root: TreeNode
        :type sum: int
        :rtype: List[List[int]]
        """
        if not root: return []
        else:
            ret = []
            dfs(root, [], sum, ret)
            return ret
```

