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
    ListNode* removeElements(ListNode* head, int val) {
        if(head==nullptr)return nullptr;
        auto p=head;
        
        //åºå½åå¤çå¤´é¨æé
        while(p->val==val)
        {
            p=p->next;
            if(p==nullptr)return p;
        }
        
        auto h=p;
        ListNode* pre=nullptr;
        while(p)
        {
            if(p->val==val)
            {
                pre->next=p->next;
                p=p->next;
            }
            else
            {
                pre=p;
                p=p->next;
            }
        }
        return h;
    }
};