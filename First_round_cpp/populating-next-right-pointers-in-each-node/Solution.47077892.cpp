/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
 #include<math>

class Solution {
public:
    void connect(TreeLinkNode *root) {
        if(!root)return;
         
         deque<TreeLinkNode*> d;
         
         d.push_back(root);
         
         d[0]->next=nullptr;
         
         int num=0;
         
         while(1)
         {
            for(int i=0;i<int(pow(2,num));i++)
            {
                if(d.front()->left)
                {
                    d.push_back(d.front()->left);
                    d.push_back(d.front()->right);
                }
                
                d.pop_front();
                
            }
            if(d.empty()==true)break;
            
                int x=0;
                for(;x<d.size()-1;x++)
                 {
                     d[x]->next=d[x+1];
                 }
                 d[x]->next=nullptr;
                 
            num++;
         }
         
    }
};