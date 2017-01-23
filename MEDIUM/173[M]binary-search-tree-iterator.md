[原题](https://leetcode.com/problems/binary-search-tree-iterator/)

题意：

实现二叉搜索树的迭代器。

使用栈进行模拟即可。

```Python
# Definition for a  binary tree node
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class BSTIterator(object):
    def __init__(self, root):
        """
        :type root: TreeNode
        """
        self.stack = []
        p = root
        while p:
            self.stack.append(p)
            p = p.left
        
    def hasNext(self):
        """
        :rtype: bool
        """
        return len(self.stack) != 0
        
    def next(self):
        """
        :rtype: int
        """
        ret = self.stack.pop()
        p = ret.right
        while p:
            self.stack.append(p)
            p = p.left
        return ret.val

# Your BSTIterator will be called like this:
# i, v = BSTIterator(root), []
# while i.hasNext(): v.append(i.next())
```
