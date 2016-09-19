/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
 
struct TreeNode* buildTree(int* pre, int n, int* in, int m) {
    //å°ä¸ä¸ªåºååæä¸é¨åï¼éå½è§£å³
   
    if(n==0)return NULL;
    struct TreeNode* root=(struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->val=pre[0];
    int index;
    for(index=0;index<n;index++){
        if(in[index]==pre[0])break;
    }
    int leftsize=index;
    int rightsize=n-1-leftsize;
    root->left=buildTree(pre+1,leftsize,in,leftsize);
    root->right=buildTree(pre+leftsize+1,rightsize,in+index+1,rightsize);
}