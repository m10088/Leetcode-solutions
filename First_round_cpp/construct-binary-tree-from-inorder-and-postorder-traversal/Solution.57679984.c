

struct TreeNode* buildTree(int* in, int n, int* pre, int m) {
    //å°ä¸ä¸ªåºååæä¸é¨åï¼éå½è§£å³
    if(n==0)return NULL;
    struct TreeNode* root=(struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->val=pre[n-1];
    int index;
    for(index=0;index<n;index++){
        if(in[index]==pre[n-1])break;
    }
    int leftsize=index;
    int rightsize=n-1-leftsize;
    
    root->left=buildTree(in,leftsize,pre,leftsize);
    root->right=buildTree(in+index+1,rightsize,pre+leftsize,rightsize);
}