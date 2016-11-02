[原题](https://leetcode.com/problems/kth-smallest-element-in-a-bst/)

题意：二叉搜索树中第k小的元素。

非递归解决：中序遍历到数组，然后给出数组的第k小的值。

递归解决：


- 可以先使用一次遍历求出每个节点代表子树的大小。

如果语言类型是ducktype，直接绑定，否则hash即可。

然后使用常规的递归算法。

```
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

def calculate_size(root):
    if not root:
        return 0
    root.size = calculate_size(root.left) + calculate_size(root.right) + 1
    return root.size

class Solution(object):
    def kthSmallest(self, root, k):
        """
        :type root: TreeNode
        :type k: int
        :rtype: int
        """
        def Size(root):
            return 0 if not root else root.size
        calculate_size(root)
        def dfs(root, k):
            if Size(root.left) == k - 1:
                return root.val
            elif Size(root.left) > k - 1:
                return dfs(root.left, k)
            else:
                return dfs(root.right, k-1-Size(root.left))
        return dfs(root, k)
        
```

如果二叉树要经常改变，那么就设计到更新子树大小的问题，从底向上更新。这样又要保存parent的节点信息，非常麻烦。


- 不保存节点的信息，直接每次都进行子树大小的查询。




## 另有一位大神的方法如下。

```C++
class Solution { 
public:
    int kthSmallest(TreeNode* root, int k) {
        return smallest(root, k);
    } 
private:
    int smallest(TreeNode* node, int& k) {
        if (!node) return -1;
        int val = smallest(node -> left, k);
        if (!k) return val;
        if (!--k) return node -> val; 
        return smallest(node -> right, k);
    }
};
```

