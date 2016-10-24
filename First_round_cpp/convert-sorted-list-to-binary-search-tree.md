```c++
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    
    TreeNode* sortedListToBST(ListNode* head) {
         if(!head)return NULL;
         TreeNode* root;
         Recursive(head,root);
         return root;
    }
public:
    void Recursive(ListNode*head,TreeNode* &root){
        if(!head)return;
        if(head->next==NULL){
            root=new TreeNode(head->val);
            return;
        }
        auto mid=splitlist(head);
        root=new TreeNode(mid->val);
        Recursive(head,root->left);
        Recursive(mid->next,root->right);
    }

public:
ListNode* splitlist(ListNode*head){
    ListNode*fast=head,*slow=head;
    while(1){
        
        fast=fast->next->next;
        slow=slow->next;
        if(fast==NULL||fast->next==NULL||fast->next->next==NULL){
            break;
        }
    }
```
