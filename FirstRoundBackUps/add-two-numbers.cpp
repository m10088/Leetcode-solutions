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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        vector<int> res;
        auto p=l1;
        auto q=l2;
        while(p&&q)
        {

            res.push_back(p->val+q->val);
            p=p->next;
            q=q->next;
        }

        if(!p&&!q){}
        else if(!p&&q)
        {
            while(q)
            {
                res.push_back(q->val);
                q=q->next;
                
            }
        }
        else
        {
            while(p)
            {
                res.push_back(p->val);
                p=p->next;
                
            }
        }


        int j=0;

        for(auto q=res.begin();q!=res.end();q++)
        {
            if(((*q)+j)>=10)
            {

                 int t=((*q)+j)/10;
                *q=((*q)+j)%10;
                 j=t;
            }
            else
            {
                *q=*q+j;
                j=0;
            }
        }
        if(j==1)
            res.push_back(j);

       ListNode*head=new ListNode(res[0]);
       ListNode**p0=&(head->next);
       for(int i=1;i<res.size();i++)
       {
           *p0=new ListNode(res[i]);
           p0=&((*p0)->next);
       }
    return head;
    }
};