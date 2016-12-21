/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 //å¦æä¸¤ä¸ªå¼æ­£å¥½è·¨è¿å½åèç¹ï¼å°±è¿åå½åèç¹ï¼å¦æå¤§äºï¼å¨å³å­æ ä¸­æ¾ï¼å¦æå°äºå¨å·¦å­æ ä¸­æ¾
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root)
            return root;
        int bigger=std::max(p->val,q->val);
        int smaller=std::min(p->val,q->val);
        if(smaller<=root->val&&root->val<=bigger){
            return root;
        }else if(smaller>root->val){
            return lowestCommonAncestor(root->right,p,q);
        }else{
            return lowestCommonAncestor(root->left,p,q);
        }
    }
};