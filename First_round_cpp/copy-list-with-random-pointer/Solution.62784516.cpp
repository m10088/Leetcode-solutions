/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        RandomListNode* res = NULL;
        if(!head) return res;
        res = new RandomListNode(head->label);
        m[head]=res;
        auto q=res;//æå¥½ä¸è¦ä½¿ç¨å¼ç¨ï¼å¼ç¨ä¸è½è§£é¤ç»å®
        auto p=head->next;//åéåä¸éé¾è¡¨å°ç´çè¿æ¥å¥½
        while(p){
            q->next=new RandomListNode(p->label);
            m[p]=q->next;
            q=q->next;
            p=p->next;
        }
        //ç¶åéæ°éåé¾è¡¨ï¼å°æ²¡æå å¥çrandomæéå å¥
         p=head,q=res;
        while(p){
            auto rp=p->random;
            q->random=m[rp];
            q=q->next;
            p=p->next;
        }
        return res;
    }
    
private:
    map<RandomListNode*,RandomListNode*> m; 
};