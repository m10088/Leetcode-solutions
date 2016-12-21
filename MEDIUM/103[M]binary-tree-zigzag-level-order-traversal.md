[原题](https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/)

题意：

二叉树的层次输出，锯齿形状的。

参考[103],[107]即可，加上一个标志位zigflag

```
def zigzagLevelOrder(self, root):
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
        # add a zig flag is OK
        zigflag = 0 # 0 -> | 1 <-
        while len(q) > 0:
            fro = q.pop(0)
            tmpRes.append(fro.val)
            if fro.left:
                q.append(fro.left)
            if fro.right:
                q.append(fro.right)
            last -= 1
            if last == 0:
                ret.append(tmpRes) if zigflag == 0 else ret.append(tmpRes[::-1])
                tmpRes = []
                last, zigflag = len(q), 1-zigflag
        return ret
```