#define INF 0x3f3f3f3f
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
unordered_map<TreeNode*,int> m;
unordered_map<TreeNode*,int>ram;
int dfs(TreeNode*root){
   
    if(!root)return ram[root]=0;
    
     if(ram.find(root)!=ram.end()){
        return ram[root];
    }
    
    int tmp1=dfs(root->left)+dfs(root->right)+root->val;
    int tmp2=dfs(root->left)+root->val;
    int tmp3=dfs(root->right)+root->val;
    int tmp4=root->val;
    
    m[root]=std::max(tmp1,std::max(tmp2,std::max(tmp3,tmp4)));
    
    return ram[root]=std::max(tmp2,std::max(tmp3,tmp4)); 
}
class Solution {
public:
    int maxPathSum(TreeNode* root) {
        if(!root)return 0;
        m.clear();
        ram.clear();
        dfs(root);
        int maxer=-INF;
        for(auto p=m.begin();p!=m.end();p++){
            maxer=std::max(maxer,p->second);
        }
        return maxer;
    }
};