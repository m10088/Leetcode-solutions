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
ListNode* splitlist(ListNode*head){//åå²é¾è¡¨æä¸¤é¨å,è¦æ±ç¬¬äºé¨åæå¤æ¯ç¬¬ä¸é¨åå¤ä¸ä¸ªåç´ 
    ListNode*fast=head,*slow=head;
    while(1){
        //å¿«æéè¿ä¸¤ä¸ª
        fast=fast->next->next;
        slow=slow->next;
        if(fast==NULL||fast->next==NULL||fast->next->next==NULL){
            break;
        }
    }
    //å¹¶ä¸å°ä¸ä¸ä¸ªçæåä¸ä¸ªç½®ä¸ºé¶
    ListNode*p=head;
    while(p->next!=slow){
        p=p->next;
    }
    p->next=NULL;
    //è¿åä¸­é´çå¼
    return slow;
    }
};