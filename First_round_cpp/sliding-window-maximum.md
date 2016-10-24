```c++
struct Node{
    int index;
    int val;
    Node(int index,int val):index(index),val(val){}
    Node(){}
    bool operator < (const Node x)const {
        if(val<x.val)return true;
        else if(val>x.val)return false;
        else return index<x.index;
    }
};
map<Node,int> m;
int GetMax(){
    auto p=m.end();
    return ((--p)->first).val;
}
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& a, int k) {
        m.clear();
        vector<int> res;
        if(a.size()==0)return res;
        
        for(int i=0;i<k;i++){
            m[Node(i,a[i])]=1;
        }
        
        
        res.push_back(GetMax());
        for(int i=k;i<a.size();i++){
            m.erase(Node(i-k,a[i-k]));
            m[Node(i,a[i])]=1;
            res.push_back(GetMax());
            
        }
        return res;
    }
}
```
