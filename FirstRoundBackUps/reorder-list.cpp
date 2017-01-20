/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
ListNode* reverseList(ListNode* head) {
        if(!head)return head;
        if(!head->next)return head;
        auto p=head;
       ListNode* pre=nullptr;
        while(p)
        {
            auto q=p->next;
            p->next=pre;
            pre=p;
            p=q;
            
        }
        return pre;
}
ListNode* splitlist(ListNode*head){
    ListNode*fast=head,*slow=head;
    while(1){
        
        fast=fast->next->next;
        slow=slow->next;
        if(fast==NULL||fast->next==NULL||fast->next->next==NULL){
            break;
        }
    }
    slow=slow->next;
    
    ListNode*p=head;
    while(p->next!=slow){
        p=p->next;
    }
    p->next=NULL;
    
    return slow;
}


class Solution {
public:
    void reorderList(ListNode* li) {
        if(!li)return;
        if(li->next==NULL)return;
        if(li->next->next==NULL)return;
        ListNode*head=new ListNode(-1);
        head->next=li; 
        
        auto q=head;
        auto p=head->next;
        auto mid=splitlist(li);
        mid=reverseList(mid);
        ListNode*sec=new ListNode(-1);
        sec->next=mid;
        q=head->next;
        p=q->next;
        auto psec=sec->next;
        while(p){
            auto tmp=psec->next;
            q->next=psec;
            psec->next=p;
            q=p;
            p=p->next;
            psec=tmp;
        }
        if(psec){
            q->next=psec;
        }
        
        
    }
};