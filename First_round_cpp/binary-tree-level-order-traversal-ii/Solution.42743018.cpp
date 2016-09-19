/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 #include<deque>
 #include<algorithm>
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int> > res;
        vector<vector<TreeNode*> > link; 
        if(!root)return res;
        vector<TreeNode*> fl;
        fl.push_back(root);
        link.push_back(fl);
        while(1)
        {
            vector<TreeNode*> fl;
            bool nochild=true;
            for(auto vm:link.back())
            {
                if(vm->left){fl.push_back(vm->left);nochild=false;}
                if(vm->right){fl.push_back(vm->right);nochild=false;}
                
            }
            if(nochild)break;
            link.push_back(fl);
            
        }
        //ä»¥ä¸å»ºç«äºåç§°ä¸ºlinkçä¸ä¸ªç´¢å¼è¡¨ï¼æå±åå¸ï¼ç±ä¸å¾ä¸ã
        for(int p=link.size()-1;p>=0;p--)
        {
            vector<int> layer;
            for(auto&m:link[p])
            {
                layer.push_back(m->val);
            }
            res.push_back(layer);
        }
        return res;
    }
};