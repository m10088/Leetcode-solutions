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
    //è§£æ³ï¼å¯¹é¾è¡¨è¿è¡æå¥æåº
    ListNode* insertionSortList(ListNode* li) {
        if(!li||!(li->next))return li;
        //å»ºç«ä¸ä¸ªå¤´èç¹
        ListNode*head=new ListNode(-1);
        head->next=li;
        ListNode*begin=head->next->next;
        head->next->next=NULL;
        
        while(begin){
            auto tmp=begin->next;
            ListNode*q=head,*p=head->next;
            int flag=0;//é»è®¤æ¯æ²¡ææå¥å°ä¸­é´èç¹ï¼èæ¯èç»å°æå
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