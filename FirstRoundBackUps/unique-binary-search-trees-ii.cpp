/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
 vector<TreeNode*> dfs(const vector<int>&v){
    vector<TreeNode*> res;
    if(v.size()==0){
        TreeNode*root=NULL;
        res.push_back(root);
        return res;
    }
    else if(v.size()==1){
        TreeNode* root=new TreeNode(v[0]);
        res.push_back(root);
        return res;
    }else{
        
        for(int i=0;i<v.size();i++){
            auto lefter=dfs(vector<int>(v.begin(),v.begin()+i));
            auto righter=dfs(vector<int>(v.begin()+i+1,v.end()));
            
            for(int j=0;j<lefter.size();j++){
                for(int k=0;k<righter.size();k++){
                    TreeNode*root=new TreeNode(v[i]);
                    root->left=lefter[j];
                    root->right=righter[k];
                    res.push_back(root);
                }
            }
        }
        
        return res;
    }
 }
class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        vector<TreeNode*> res;
        if(n==0)return res;
        vector<int> v;
        for(int i=1;i<=n;i++){
            v.push_back(i);
        }
        return dfs(v);
    }
};