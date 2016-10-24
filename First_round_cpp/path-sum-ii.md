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
 
 void f( TreeNode*p , vector<int> path , vector<vector<int> >& res)
 {
     if(p->left==nullptr&&p->right==nullptr)
     {
         path.push_back(p->val);
         res.push_back(path);
     }
     else if(p->left==nullptr&&p->right)
     {
         vector<int> v=path;
         v.push_back(p->val);
         f(p->right,v,res);
     }
     else if(p->left&&p->right==nullptr)
     {
         vector<int> v=path;
         v.push_back(p->val);
         f(p->left,v,res);
     }
     else
     {
         vector<int> v1=path;
         v1.push_back(p->val);
         f(p->right,v1,res);
         
         vector<int> v2=path;
         v2.push_back(p->val);
         f(p->left,v2,res);
     }
 }
 
 int v2int(vector<int>&v)
 {
     
    return std::accumulate(v.begin(),v.end(),0);
 }
class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> res;
```
