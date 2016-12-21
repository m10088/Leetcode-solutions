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
        v.push_back(num+1);
    }
    else if(T->left&&!T->right)
    {
        add(T->left,num+1,v);
    }
    else if(T->right&&!T->left)
    {
        add(T->right,num+1,v);
    }
    else
    {
         add(T->left,num+1,v);
         add(T->right,num+1,v);
    }
}
class Solution {
public:
     int minDepth(TreeNode* root) {
         if(!root)return 0;
       vector<int> path;
       add(root,0,path);
       return *std::min_element(path.begin(),path.end());
    }
};