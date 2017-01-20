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
    ListNode* deleteDuplicates(ListNode*li) {
        if(!li)return li;
        ListNode*head=new ListNode(-1);
        head->next=li;
        map<int,int> times;
        auto p=head->next;
        while(p){
            times[p->val]++;
            p=p->next;
        }
        auto q=head;
        p=q->next;
        while(p){
            if(times[p->val]>1){
                q->next=p->next;
                p=p->next;
            }else{
                q=p;
                p=p->next;
            }
        }
        return head->next;
    }
};