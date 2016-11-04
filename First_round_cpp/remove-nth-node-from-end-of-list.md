```c++
/**
* Definition for singly - linked list.
* struct ListNode {
    * int val;
    * ListNode * next;
    * ListNode(int x) : val(x), next(NULL) {}
    * };
*/
class Solution {
    public:
        ListNode* removeNthFromEnd(ListNode* head, int n) {
            auto p = head;
            auto q = head;
            int i = 1;
            while (i < n) {
                q = q->next;
                i++;
            }

            int flag = 0;
            while (1) {
                q = q->next;
                if (q == nullptr) {
                    flag = 1;
                    break;
                }
                if (q->next == nullptr)
                    break;
                p = p->next;
            }
            if (flag == 0) {
                p->next = p->next->next;
                return head;
            }
            else
            {
                return p->next;
            }

        }
}
```
