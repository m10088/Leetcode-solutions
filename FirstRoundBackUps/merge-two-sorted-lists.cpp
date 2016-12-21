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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(!l2&&!l1)return nullptr;
        if(!l2&&l1)return l1;
        if(!l1&&l2)return l2;
        ListNode*root=new ListNode(-1);
        ListNode**pt=&(root->next);
        auto p=l1;
        auto q=l2;
        while(p&&q)
        {
            if(p->val<=q->val)
            {
               *pt=new ListNode(p->val);
               p=p->next;
            }
            else
            {
               *pt=new ListNode(q->val);
               q=q->next;
            }
            pt=&((*pt)->next);
        }
        if(!p&&!q){}
        else if(!p&&q)
        {
            while(q)
            {
                *pt=new ListNode(q->val);
                q=q->next;
                pt=&((*pt)->next);
            }
        }
        else
        {
            while(p)
            {
                *pt=new ListNode(p->val);
                p=p->next;
                pt=&((*pt)->next);
            }
        }
        return root->next;
    }
};