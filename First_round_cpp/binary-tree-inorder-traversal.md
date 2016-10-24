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
struct Node{
    TreeNode*ptr;
    int flag;
    Node(){
        ptr=NULL;
        flag=0;
    }
    Node(TreeNode*p):ptr(p){}
};
#define N 10007
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        if(!root)return res;
        Node stack[N];
        int cur=0;
        stack[cur++]=Node(root);
        while(cur>0){
            TreeNode*back=stack[cur-1].ptr;
            if(stack[cur-1].flag==0){
                stack[cur-1].flag=1;
                if(back->left==NULL){}
                else stack[cur++]=Node(back->left);
            }else if(stack[cur-1].flag==1){
                res.push_back(back->val);
                stack[cur-1].flag=2;
                if(back->right==NULL){}
                else stack[cur++]=Node(back->right);
            }else{
                cur--;
            }
        }
        return res;
    }
}
```
