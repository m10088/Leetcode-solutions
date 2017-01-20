/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
int GetSize(ListNode* head){
    auto p=head->next;
    int n=0;
    while(p){
        n++;
        p=p->next;
    }
    return n;
}
class Solution {
public:
    ListNode* rotateRight(ListNode* li, int k) {
        
        ListNode*head=new ListNode(-1);
        head->next=li;
        
        if(!li)return li;
        int n=GetSize(head);
        k=k%n;
        if(k==0)return li;
        auto q=head,p=q->next;
        int cnt=0,flag=0;
        while(p){
            
            q=p;
            p=p->next;
            cnt++;
            if(cnt==n-k){
                flag=1;
                break;
            }
        }
        
        auto tail=p;
        while(tail->next){
            tail=tail->next;
        }
        
        if(flag==0)return head->next;
        q->next=NULL;
        tail->next=head->next;
        head->next=p;
        return head->next;
    }
};