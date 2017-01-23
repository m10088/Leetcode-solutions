[原题](https://leetcode.com/problems/delete-node-in-a-bst)

题意:

bst中删除一个指定的节点。

题解:


如果删除的是中间的节点，那么首先选择一个右边子树中最小的一个值，然后交换。然后递归的在右子树中删除。

本来以为python不能传递引用（like Cpp）但是，实时上也是可以实现的。

```Python
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def getMin(self, root):
        p = root
        while p.left:
            p = p.left
        return p.val
    
    
        
    def deleteNode(self, root, key):
        """
        :type root: TreeNode
        :type key: int
        :rtype: TreeNode
        """
        if not root: return root
        if root.val > key: root.left = self.deleteNode(root.left, key)
        elif root.val < key: root.right = self.deleteNode(root.right, key)
        else:
            if not root.left: return root.right
            elif not root.right: return root.left
            else:
                root.val = self.getMin(root.right)
                root.right = self.deleteNode(root.right, root.val)
        return root
        
        
```
