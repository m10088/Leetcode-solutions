/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 void GetSize(TreeNode*root,int&size){
     if(root){
        size++;
        GetSize(root->left,size);
        GetSize(root->right,size);
     }
     
 }
 
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        int leftsize=0,rightsize=0;
        GetSize(root->left,leftsize);
        GetSize(root->right,rightsize);
        if(k==leftsize+1)return root->val;
        else if(k<leftsize+1) return kthSmallest(root->left,k);
        else return kthSmallest(root->right,k-(leftsize+1));
    
    }
};