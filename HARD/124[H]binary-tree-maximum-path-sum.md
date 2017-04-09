[原题](https://leetcode.com/problems/binary-tree-maximum-path-sum)

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
    def maxPathSum(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        if not root: return 0
        mp = dict()
        # map[Node] = [Bigger, SecondBigger]
        # 用于记录通过节点的两条不会重合的路径的最大值和第二大值
        def dfs(root):
            if not root: return
            dfs(root.left)
            dfs(root.right)
            
            if not root.left and not root.right:
                mp[root] = [root.val]
            elif root.left and not root.right:
                mmax = max(root.val, max(mp[root.left]) + root.val)
                mp[root] = [mmax]
            elif root.right and not root.left:
                mmax = max(root.val, max(mp[root.right]) + root.val)
                mp[root] = [mmax]
            else:
                # 对于两条路径都能行的通的情况
                # 每边的路径都有两种选择
                mp[root] = []
                # 左边
                mp[root].append(max(root.val, max(mp[root.right]) + root.val))
                mp[root].append(max(root.val, max(mp[root.left]) + root.val))
                
        dfs(root)
        ret = float('-inf')
        for node, path in mp.items():
            # print node.val, path
            if len(path) == 2:
                ret = max(ret, path[0] + path[1] - node.val)
            else:
                ret = max(ret, path[0])
        return ret
        
                
```