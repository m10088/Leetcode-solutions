```c++
/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        RandomListNode* res = NULL;
        if(!head) return res;
        res = new RandomListNode(head->label);
        m[head]=res;
        auto q=res;
        auto p=head->next;
        while(p){
            q->next=new RandomListNode(p->label);
            m[p]=q->next;
            q=q->next;
            p=p->next;
        }
        
         p=head,q=res;
        while(p){
            auto rp=p->random;
            q->random=m[rp];
            q=q->next;
            p=p->next;
        }
        return res;
    }
    
private:
    map<RandomListNode*,RandomListNode*> m; 
}
```
