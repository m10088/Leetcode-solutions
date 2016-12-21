/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 //æè·¯ï¼åå«æé ä¸¤ä¸ªé¾è¡¨ï¼ç¶ååå¹¶
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(!head)return head;
        if(!(head->next))return head;
        ListNode*even=head->next,*odd=head;
        auto p=head;
        auto q=head->next;
        while(1){
            auto tmpp=q->next;
            p->next=q->next;
            p=tmpp;
            if(p==NULL){
                q->next=NULL;
                break;
            }
            auto tmpq=p->next;
            q->next=p->next;
            q=tmpq;
            if(q==NULL){
                p->next=NULL;
                break;
            }
        }
        //åä¸ºä¸¤ä¸ªé¾è¡¨ç¶åèç»èµ·æ¥å³å¯
        p=head;
        while(p->next!=NULL){
            p=p->next;
        }
        p->next=even;
        return head;
    }
};