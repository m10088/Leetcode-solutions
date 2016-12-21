/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
int GetSize(ListNode* head){//å¸¦å¤´èç¹çé¾è¡¨
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
        //å»ºç«è¡¨å¤´èç¹
        ListNode*head=new ListNode(-1);
        head->next=li;
        //å¤æ­å ä¸ªç¹æ®æåµ
        if(!li)return li;
        int n=GetSize(head);
        k=k%n;
        if(k==0)return li;
        auto q=head,p=q->next;
        int cnt=0,flag=0;//é»è®¤æ æ
        while(p){
            
            q=p;
            p=p->next;
            cnt++;
            if(cnt==n-k){
                flag=1;
                break;
            }
        }
        //æ¾å°å°¾å·´èç¹çåä¸ä¸ªèç¹
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