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

template<typename T>
T StringTo(const std::string &s){
    std::stringstream sout;
    sout << s;
    T tmp;
    sout >> tmp;
    return tmp;
}


template<typename T>
std::vector<T> StringToVec(const std::string &s){
    std::stringstream sout;
    sout << s;
    std::vector<T> res;
    T tmp;
    while(sout >> tmp){
        res.push_back(tmp);
    }
    return res;
}
template<typename T>

std::string ToString(T x){
    std::stringstream sout;
    sout << x;
    return sout.str();
}


class Codec{
public:
    
    
    void Preorder(TreeNode*root,vector<string>&res){
        if(root){
            res.push_back(ToString<int>(root->val));
            Preorder(root->left,res);
            Preorder(root->right,res);
        }else{
```
