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
    
    ListNode* insertionSortList(ListNode* li) {
        if(!li||!(li->next))return li;
        
        ListNode*head=new ListNode(-1);
        head->next=li;
        ListNode*begin=head->next->next;
        head->next->next=NULL;
        
        while(begin){
            auto tmp=begin->next;
            ListNode*q=head,*p=head->next;
            int flag=0;
            while(p){
                if(p->val<begin->val){
                    q=p;
                    p=p->next;
                }else{
                    q->next=begin;
                    begin->next=p;
                    flag=1;
                    break;
                }
            }
            if(!flag){
                q->next=begin;
                begin->next=NULL;
            }
            begin=tmp;
        }
        return head->next;
        
    }
};