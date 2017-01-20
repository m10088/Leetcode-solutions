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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    
        vector<vector<int>> res;
        if(!root)return res;
        vector<vector<TreeNode*>> v;
        vector<TreeNode*> fir={root};
        v.push_back(fir);
        bool update=true;
        int cur=0;
        while(1){
            update=false;
            vector<TreeNode*> tmp;
            for(int i=v[cur].size()-1;i>=0;i--){
                if(cur%2){
                    if(v[cur][i]->left){
                        tmp.push_back(v[cur][i]->left);
                        update=true;
                    }
                    if(v[cur][i]->right){
                        tmp.push_back(v[cur][i]->right);
                        update=true;
                    }
                }else{
                     if(v[cur][i]->right){
                        tmp.push_back(v[cur][i]->right);
                        update=true;
                     }
                     if(v[cur][i]->left){
                        tmp.push_back(v[cur][i]->left);
                        update=true;
                    }
                }
                
            }
            if(update){
                    v.push_back(tmp);
                    cur++;
            }else{
                break;
            }
        }
        for(int i=0;i<v.size();i++){
            vector<int> tmp;
            if(true){
                for(int j=0;j<v[i].size();j++){
                    tmp.push_back(v[i][j]->val);
                }
            }else{
                for(int j=v[i].size()-1;j>=0;j--){
                    tmp.push_back(v[i][j]->val);
                }
            }
            res.push_back(tmp);
        }
        return res;
        
    }
};