[原题](https://leetcode.com/problems/binary-tree-postorder-traversal/)

题意：

后续遍历二叉树。

```
class Solution(object):
    def postorderTraversal(self, root):
        """
        :type root: TreeNode
        :rtype: List[int]
        """
        
        return self.postorderTraversal(root.left) + self.postorderTraversal(root.right) + [root.val] if root else []
```