```c++
/**
* Definition for binary tree
* struct TreeNode {
    * int val;
    * TreeNode * left;
    * TreeNode * right;
    * TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    * };
*/
class BSTIterator {
    public:

        vector<TreeNode*> stack;
        BSTIterator(TreeNode *root) {
            auto p = root;
            while (p) {
                stack.push_back(p);
                p = p->left;
            }
        }

        /** @return whether we have a next smallest number */
        bool hasNext() {
            return stack.empty() == false;
        }

        /** @return the next smallest number */
        int next() {
            auto top = stack.back();
            int res = top->val;
            
            stack.pop_back();
            
            auto p = top->right;
            while (p) {
                stack.push_back(p);
                p = p->left;
            }
            return res;
        }
};

/**
* Your BSTIterator will be called like this:
* BSTIterator i = BSTIterator(root);
* while (i.hasNext()) cout << i.next();
*
```
