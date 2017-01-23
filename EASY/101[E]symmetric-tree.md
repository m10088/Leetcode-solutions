[原题](https://leetcode.com/problems/symmetric-tree/)

题意：

判断一颗二叉树是不是，镜像对称的。

实际上，我们已经完成了invert_tree和is_same_tree，因此，组合一下即可。

但是这里，提供一种更好的dfs的思路，见代码。

```Python
def dfs2(p1,p2):
    """
    Two pointers.
    p1 searches using DFS, Left-Root-Right manner.
    p2 searches using DFS, Right-Root-Left manner.
    """
    # Base case if both nodes are leaves
    if p1 == None and p2 == None:
        return True
    
    # Recurse if both of them are not null
    if p1!=None and p2!=None:
        # values for p1 and p2 must be same.
        if p1.val != p2.val:
            return False
        x = dfs2(p1.left,p2.right)
        y = dfs2(p1.right,p2.left)
        # Left of p1 is not same as right of p2 then false.
        # Simply perform "and" operation on x and y to enforce that. 
        return x and y
    
    # If only one of them is null then return False.
    return False

class Solution(object):
    def isSymmetric(self, root):
        """
        :type root: TreeNode
        :rtype: bool
        """
        if root == None:
            return True
        else:
            return dfs2(root.left,root.right)
```
