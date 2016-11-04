```c++
/**
* Definition for a binary tree node.
* struct TreeNode {
    * int val;
    * TreeNode * left;
    * TreeNode * right;
    * TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    * };
*/
struct Node {
    TreeNode*p;
    int cnt;
    Node(TreeNode*p, int cnt):p(p),cnt(cnt){}
    Node(){}
};
class Solution {
    public:
        vector<int> rightSideView(TreeNode* root) {
            
            vector<int> res;
            if (!root)return res;
            deque<Node> d;
            d.push_back(Node(root, 0));
            while (d.empty() == false) {
                auto fro = d.front();
                d.pop_front();
                int flag = 0; 
                if (d.empty() == true){flag = 1;}
                else {
                    auto sec = d.front();
                    if (fro.cnt + 1 == sec.cnt){flag = 1;}
                }

                if (flag){res.push_back(fro.p->val);}

                if (fro.p->left) {
                    d.push_back(Node(fro.p->left, fro.cnt + 1));
                }
                if (fro.p->right) {
                    d.push_back(Node(fro.p->right, fro.cnt + 1));
                }
            }
            return res;
        }
}
```
