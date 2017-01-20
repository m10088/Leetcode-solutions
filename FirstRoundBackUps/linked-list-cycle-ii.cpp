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
    
    /*
    å¥½æ³å¦æå¨å¤´ç»ç¹ä½ç½®åç¸éç¹ä½ç½®åå«åæ´¾åºä¸¤åè·æ­¥éæï¼å¹¶ä¸ä»ä»¬é½æ¯æ¬¡åªè·ä¸æ­¥ï¼å¥½åä¼å¨ç¯çå¥å£ç¹ç¸éåï¼ï¼ï¼
    */
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow = head;
        ListNode *fast = head;
        int flag=0;
        do{
            if(!slow || !fast)
                return false;
            slow=slow->next;
            fast=fast->next;
            if(!fast)break;
            else{
                fast=fast->next;
                if(slow==fast){
                    flag=1;break;
                }
            }
        }while(1);
        if(flag==0)return NULL;
        ListNode*p=head,*q=slow;
        while(1){
            if(p!=q){
                p=p->next,q=q->next;
            }else{
                break;
            }
        }
        return p;
        
    }
};