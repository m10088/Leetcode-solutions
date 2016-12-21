/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
    ListNode* swapPairs(ListNode* head)
    {
      //åå¦ç©ºè¡¨ï¼è¿å 
      if(!head)return head;
      //åå¦åªæä¸ä¸ªæ°æ®ï¼è¿å
      if(!head->next)return head;
      
      auto former=new ListNode(-1);
      auto p=head;
      auto res=head->next;
      auto q=head->next;
      while(1)
      {
          auto n=q->next;
          former->next=q;
          q->next=p;
          former=p;
          if(n==nullptr)
          {
              p->next=nullptr;
              break;
          }
          if(n->next==nullptr)
          {
              former->next=n;
              break;
          }
          q=n->next;
          p=n;
          
      }
      return res;
      
      
      
    }
};