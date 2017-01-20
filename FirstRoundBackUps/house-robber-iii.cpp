/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
unordered_map<TreeNode*,int> _true;
unordered_map<TreeNode*,int> _false;
class Solution {
public:
    int dfs_true(TreeNode*root){
        if(_true.find(root)!=_true.end()){
            return _true[root];
        }
        if(!root){
            return 0;
        }else{
            return _true[root]=dfs_false(root->left)+dfs_false(root->right)+root->val;
        }
    }
    int dfs_false(TreeNode*root){
        if(_false.find(root)!=_false.end()){
            return _false[root];
        }
        if(!root){
            return 0;
        }else{
            return _false[root]=std::max(dfs_true(root->left),dfs_false(root->left))+std::max(dfs_true(root->right),dfs_false(root->right));
        }
    }
    int rob(TreeNode* root) {
        _true.clear();
        _false.clear();
        return std::max(dfs_true(root),dfs_false(root)); 
    }
};