```c++
int maxDepth(TreeNode* root) {
        if(!root)return 0;
        else
         {
             int i=maxDepth(root->left);
             int j=maxDepth(root->right);
             if(j>=i)return j+1;
             else return i+1;
         }
}
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 bool fxy(int x,int y)
 {
     if(x-y>=2||y-x>=2)return false;
     else return true;
 }
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if(!root)return true;
        if( fxy( maxDepth(root->left),maxDepth(root->right) ) )
        {
            return isBalanced(root->left)&&isBalanced(root->right);

        }
        else
        {return false;}
    }
}
```
