[原题](https://leetcode.com/problems/binary-tree-level-order-traversal/)

bfs按层次输出一棵树。

为了标记什么时候到大一层的结束位置，设置标志变量last。

```
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def levelOrderBottom(self, root):
        """
        :type root: TreeNode
        :rtype: List[List[int]]
        """
        if not root: return []
        q = []
        q.append(root)
        tmpRes = []
        ret = []
        last = 1
        while len(q) > 0:
            fro = q.pop(0)
            tmpRes.append(fro.val)
            if fro.left:
                q.append(fro.left)
            if fro.right:
                q.append(fro.right)
            last -= 1
            if last == 0:
                ret.append(tmpRes)
                tmpRes = []
                last = len(q)
        return ret[::-1]
```