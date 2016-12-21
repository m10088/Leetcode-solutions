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
    int maxDepth(TreeNode* root) {
        if(!root)return 0;
        else
         {
             int i=maxDepth(root->left);
             int j=maxDepth(root->right);
             if(j>=i)return j+1;
             else return i+1;
         }
    }
};