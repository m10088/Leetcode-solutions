/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
TreeNode*last;
vector<TreeNode*> v;
void dfs(TreeNode*root){
    if(root){
        dfs(root->left);
        int val=root->val;
        if(last){
            if(last->val>val){
                v.push_back(last);
                v.push_back(root);
            }
        }
        last=root;
        dfs(root->right);
    }
}
class Solution {
public:
    void recoverTree(TreeNode* root) {
        if(!root)return;
        v.clear();
        last=NULL;
        dfs(root);
        if(v.size()==2){
            auto tmp=v[0]->val;
            v[0]->val=v[1]->val;
            v[1]->val=tmp;
        }else if(v.size()==4){
            auto tmp=v[0]->val;
            v[0]->val=v[3]->val;
            v[3]->val=tmp;
        }else{
            cout<<"wrong"<<endl;
        }
            
    }
};