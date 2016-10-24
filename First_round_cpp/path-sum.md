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
 #include<algorithm>
void add(TreeNode*T,int num,vector<int>&v)
{
    if(!T->left&&!T->right)
    {
        v.push_back(num+T->val);
    }
    else if(T->left&&!T->right)
    {
        add(T->left,num+T->val,v);
    }
    else if(T->right&&!T->left)
    {
        add(T->right,num+T->val,v);
    }
    else
    {
         add(T->left,num+T->val,v);
         add(T->right,num+T->val,v);
    }
}
 
class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if(!root)
        {
         return false;
        }
        vector<int> path;
        add(root,0,path);
       
        if(find(path.begin(),path.end(),sum)!=path.end())return true;
        else return false;
    }
}
```
