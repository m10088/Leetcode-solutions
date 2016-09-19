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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root)return nullptr;
        if(p->left==q||p->right==q)return p;
        if(q->left==p||q->right==p)return q;
        TreeNode*b;
        TreeNode*s;
        if(p->val>q->val)
        {b=p;s=q;}
        else
        {b=q;s=p;}
        if( root->val==p->val || root->val==q->val)return root;
        if((root->val < b->val && root->val > s->val))return root;
        else if(root->val<b->val&&root->val<b->val) return lowestCommonAncestor(root->right,p,q);
        else if(root->val>s->val&&root->val>s->val) return lowestCommonAncestor(root->left,p,q); 
    }
};