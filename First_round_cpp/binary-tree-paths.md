```c++
#include<sstream>
/**
* Definition for a binary tree node.
* struct TreeNode {
    * int val;
    * TreeNode * left;
    * TreeNode * right;
    * TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    * };
*/
void dfs(TreeNode*p, vector<int>&path, vector<vector<int> > &res) {


    path.push_back(p->val);
    if (p->left == nullptr && p->right == nullptr){ res.push_back(path);}
    else if (p->left == nullptr && p->right) {
        vector<int> cp = path;
        dfs(p->right,cp,res);
    }
    else if (p->left && p->right == nullptr) {
        vector<int> cp = path;
        dfs(p->left,cp,res);
    }
    else
    {
        vector<int> cp = path;
        dfs(p->left,cp,res);
        vector<int> cp2 = path;
        dfs(p->right,cp2,res);
    }


}
class Solution {
    public:
        vector<string> binaryTreePaths(TreeNode* root) {
            vector<string> strres;
            if (!root)return strres;
            vector<vector<int> > res;
            vector<int> path;
            dfs(root, path, res);
            for (int i = 0; i < res.size(); i++) {
                stringstream strm;
                int j = 0;
                for (; j < res[i].size() - 1; j++) {
                    strm << res[i][j] << "->";
                }
                strm << res[i][j];
                strres.push_back(strm.str());
```
