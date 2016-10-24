```c++
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
    ListNode* partition(ListNode* li, int x) {
        if(!li)return li;
        
        ListNode*head=new ListNode(-1);
        head->next=li;
        ListNode*s=new ListNode(-1);
        ListNode*t=new ListNode(-1);
        auto bs=s;
        auto bt=t;
        
        auto q=head,p=head->next;
        while(p){
            if(p->val<x){
                q->next=p->next;
                p->next=NULL;
                s->next=p;
                s=s->next;
                
                p=q->next;
            }else{
                q->next=p->next;
                p->next=NULL;
                t->next=p;
                t=t->next;
                
                p=q->next;
            }
        }
        
        s->next=bt->next;
        return bs->next;
        
        
    }
}
```
