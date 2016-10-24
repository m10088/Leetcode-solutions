```c++
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
    void Recursive(const vector<int>&v,TreeNode* &root){
        if(v.size()==0)return;
        auto mid=(v.size()-1)/2;
        root=new TreeNode(v[mid]);
        Recursive(vector<int>(v.begin(),v.begin()+mid),root->left);
        Recursive(vector<int>(v.begin()+mid+1,v.end()),root->right);
    }
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        TreeNode*root=NULL;
        Recursive(nums,root);
        return root;
    }
}
```
