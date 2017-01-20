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
    ListNode* reverseBetween(ListNode* li, int m, int n) {
        if(!li||!(li->next))return li;
        
        ListNode* head=new ListNode(-1);
        head->next=li;
        
        ListNode*q=head,*p=head->next;
        for(int i=1;i<m;i++){
            q=p;
            p=p->next;
        }
        
        auto tmp_head = q;
        q = tmp_head->next, p = q->next;
        auto tmp=tmp_head->next;
        
        
        int cnt=0;
        while(p){
            
            cnt++;
            if(cnt==n-m+1)break;
            q=p;p=p->next;
            q->next=tmp_head->next;
            tmp_head->next=q;
        }
        tmp->next = p;
        return head->next;
    }
};