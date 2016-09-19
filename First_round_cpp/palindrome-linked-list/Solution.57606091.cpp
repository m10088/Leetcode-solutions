/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if(!head||!(head->next))return true;
        auto mid=splitlist(head);
        mid=reverseList(mid);
        auto p=head;
        auto q=mid;
        while(p&&q){
            if(p->val==q->val){
                p=p->next;
                q=q->next;
            }else{
                return false;
            }
        }
        return true;
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
    return slow;
}
public:
ListNode* reverseList(ListNode* head) {
    if(!head)return head;
    if(!head->next)return head;
    auto p=head;
    ListNode* pre=nullptr;
    while(p){
        auto q=p->next;
        p->next=pre;
        pre=p;
        p=q;
    }
    return pre;
    
}
};