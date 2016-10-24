```c++
TreeNode* invertTree(TreeNode* root) {
        if(root)
        {
            {
                auto tmp=root->left;
                root->left=root->right;
                root->right=tmp;
            }
            invertTree(root->left);
            invertTree(root->right);
        }
        return root;
}
bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!q&&!p)return 1;
        if((!q&&p)||(!p&&q))return 0;
        if(q->val!=p->val)return 0;
        return isSameTree(p->left,q->left)&&isSameTree(p->right,q->right);
    }

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(!root)return true;
        return isSameTree(root->left,invertTree(root->right));
    }
}
```
