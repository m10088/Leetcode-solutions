/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

 struct cmp{
   bool operator ()(ListNode*p1,ListNode*p2)const{
       return p2->val < p1->val;
   }
 };
#include<queue>

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0)return NULL;
        priority_queue<ListNode*,vector<ListNode*>,cmp>q;
        int n=lists.size();
        for(int i=0;i<n;i++){
            if(lists[i])
                q.push(lists[i]);
        }
        
        ListNode*ans=new ListNode(-1),*p=ans;
        while(q.empty()==false){
            auto top=q.top();
            q.pop();
            p->next=new ListNode(top->val);
            p=p->next;
            if(top->next!=NULL){
                q.push(top->next);
            }
        }
        return ans->next;
    }
};