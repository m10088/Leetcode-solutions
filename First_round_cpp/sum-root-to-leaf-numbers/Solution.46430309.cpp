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
     
    int res=0;
    int k=v.size()-1;
    int i=0;
    for(;k>=0;k--,i++)
    {
        res=res+v[i]*pow(10,k);
    }
    return res;
 }
 
class Solution {
public:
    int sumNumbers(TreeNode* root) {
        if(!root)return 0;
        vector<vector<int> >res;
        vector<int>path;
        f(root,path,res);
        int sum=0;
        for(int i=0;i<res.size();i++)
        {
            sum+=v2int(res[i]);
        }
        return sum;
    }
};