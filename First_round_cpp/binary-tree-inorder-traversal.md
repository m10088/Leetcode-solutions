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



void f(TreeNode*p, vector<int> &v) {
    if (p) {

        f(p->left,v);
        v.push_back(p->val);
        f(p->right,v);
    }
}
class Solution {
    public:
        vector<int> inorderTraversal(TreeNode* root) {
            vector<int> res;
            f(root, res);
            return res;
        }
}
```
