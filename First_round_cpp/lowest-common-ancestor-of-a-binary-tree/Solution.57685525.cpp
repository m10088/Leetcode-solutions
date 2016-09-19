/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
bool Find(TreeNode*root,TreeNode*target){
    if(!root)return false;
    if(root==target){
        return true;
    }else{
        return Find(root->left,target)||Find(root->right,target);
    }
}
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
            if(root==p||root==q)return root;
            bool pinleft=Find(root->left,p);
            bool qinleft=Find(root->left,q);
            bool pinright=Find(root->right,p);
            bool qinright=Find(root->right,q);
            if(pinleft&&qinright || pinright&&qinleft) return root;
            else if(pinleft&&qinleft) return lowestCommonAncestor(root->left,p,q);
            else return lowestCommonAncestor(root->right,p,q);
    }
};