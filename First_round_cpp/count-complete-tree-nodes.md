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
int LeftSize(TreeNode*root) {
    auto p = root->left;
    int n = 0;
    while (p) {
        p = p->left;
        n++;
    }
    return n;
}
int RightSize(TreeNode*root) {
    auto p = root->right;
    int n = 0;
    while (p) {
        p = p->right;
        n++;
    }
    return n;
}
class Solution {
    public:
        int countNodes(TreeNode* root) {
            if (!root)return 0;
            int ls = LeftSize(root);
            int rs = RightSize(root);
            if (ls == rs) {
                return (1 << (ls + 1)) - 1;
                }else{
                return countNodes(root->left) + countNodes(root->right) + 1;
            }
        }
}
```
