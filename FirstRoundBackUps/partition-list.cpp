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
        //æ°å»ºä¸¤ä¸ªé¾è¡¨ï¼ä¿å­ä¸¤ç§ç±»åç¶åè¿è¡åå¹¶
        ListNode*head=new ListNode(-1);
        head->next=li;
        ListNode*s=new ListNode(-1);
        ListNode*t=new ListNode(-1);
        auto bs=s;
        auto bt=t;
        //å¼å§éåæ´ä¸ªé¾è¡¨
        auto q=head,p=head->next;
        while(p){
            if(p->val<x){
                q->next=p->next;
                p->next=NULL;
                s->next=p;
                s=s->next;
                //è¿åpq
                p=q->next;
            }else{
                q->next=p->next;
                p->next=NULL;
                t->next=p;
                t=t->next;
                //è¿åpq
                p=q->next;
            }
        }
        //é¾æ¥
        s->next=bt->next;
        return bs->next;
        
        
    }
};