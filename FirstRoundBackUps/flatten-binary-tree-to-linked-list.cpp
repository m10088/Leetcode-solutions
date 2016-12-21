/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
void dfs(TreeNode*root,vector<TreeNode*>&v){
    if(root!=NULL){
        v.push_back(root);
        dfs(root->left,v);
        dfs(root->right,v);
    }
}
class Solution {
public:
    void flatten(TreeNode* root) {
        if(!root)return;
        if(!(root->left)&&!(root->right))return;
        vector<TreeNode*> v;
        dfs(root,v);
        for(int i=0;i<=v.size()-2;i++){
            v[i]->right=v[i+1];
            v[i]->left=NULL;
        }
    }
};