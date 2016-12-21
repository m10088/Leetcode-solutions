/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
struct Node{
  TreeLinkNode*p;
  int layer;
  Node(){
      p=NULL;
      layer=-1;
  }
  Node(TreeLinkNode* p,int layer):p(p),layer(layer){}
};

class Solution {
public:
    void connect(TreeLinkNode *root) {
        if(!root)return;
        deque<Node> d;
        d.push_back(Node(root,0));
        int step=0;
        while(d.empty()==false){
           
            while(1){
                
                if((d.front().p->left)!=NULL){
                    d.push_back(Node(d.front().p->left,step+1));
                }
                if((d.front().p->right)!=NULL){
                    d.push_back(Node(d.front().p->right,step+1));
                }
                auto &now=d.front().p;
                d.pop_front();
                if(d.empty()==true||d.front().layer!=step){
                    now->next=NULL;
                    break;
                }else{
                    now->next=d.front().p;
                }
            }
            
            step++;
        }
    }
};