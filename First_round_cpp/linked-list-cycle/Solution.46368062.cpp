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
    bool hasCycle(ListNode *head) {
      ListNode *slow = head;

        ListNode *fast = head;

        

        do

        {

            if(!slow || !fast)

                return false;

            slow = slow->next;

            fast = fast->next;

            if(fast)

                fast = fast->next;

            else

                return false;

        } while(slow != fast);

        

        return true; 
        
        
    }
};