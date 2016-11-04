```c++
/**
* Definition for a binary tree node.
* struct TreeNode {
    * int val;
    * TreeNode * left;
    * TreeNode * right;
    * TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    * };
*/
class Solution {
    public:
        bool isSameTree(TreeNode* p, TreeNode* q) {
            if (!q&&!p)return 1;
            if ((!q && p) || (!p && q))return 0;
            if (q->val != p->val)return 0;
            return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
        }
}
```
