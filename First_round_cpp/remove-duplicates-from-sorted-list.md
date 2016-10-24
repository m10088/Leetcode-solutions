```c++
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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head)return nullptr;
        auto p=head;
        while(p)
        {
            auto x=p->val;
            auto q=p->next;
            if(!q)break;
            while(q->val==x)
            {
                q=q->next;
                if(!q)break;
            }
            p->next=q;
            p=q;
        }
        return head;
    }
}
```
