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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(!(headA&&headB))return nullptr;
        int la=0;
        int lb=0;
        auto p=headA;
        while(p)
        {
            la++;
            p=p->next;
        }
        auto q=headB;
        while(q)
        {
            lb++;
            q=q->next;
        }
        if(la>lb)
        {
            auto p=headA;
            int n=la-lb;
            while(n--)
            {
                p=p->next;
            }
            auto q=headB;
            while(p!=q)
            {
                p=p->next;
                q=q->next;
            }
            if(p&&q)return p;
            else return nullptr;
        }
        else if(la<lb)
        {
            auto p=headB;
            int n=lb-la;
            while(n--)
            {
                p=p->next;
            }
            auto q=headA;
            while(p!=q)
            {
                p=p->next;
                q=q->next;
            }
            if(p&&q)return p;
            else return nullptr;
        }
        else 
        {
            auto p=headB;
            auto q=headA;
            while(p!=q)
            {
                p=p->next;
                q=q->next;
            }
            if(p&&q)return p;
            else return nullptr;
        }
    }
};