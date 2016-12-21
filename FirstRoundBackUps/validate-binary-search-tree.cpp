/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//éç¨éå½ç®æ³æ¶åä¼æ¶åå°è¾¹çæ¯è¾çé®é¢
//æä¾ä¸ç§æ¯è¾å¥½çæè·¯ï¼åä¸­åºéåä¸éï¼ä¿å­å°æ°ç»ä¸­
void Inorder(TreeNode* root,vector<int>&res){
    if(!root)return;
    Inorder(root->left,res);
    res.push_back(root->val);
    Inorder(root->right,res);
}
class Solution {
public:
        bool isValidBST(TreeNode* root) {
            if(!root)return true;
            vector<int>res;
            Inorder(root,res);
            for(int i=0;i<res.size()-1;i++){
                if(res[i]>=res[i+1])return false;
            }
            return true;
        }
};