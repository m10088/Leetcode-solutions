```c++
#define N 1000

struct Node{
    int val,x,y;
    Node(int x,int y,int val):x(x),y(y),val(val){}
    Node(){}
    bool operator <(const Node &n2)const{
        return val<n2.val;
    }
};





class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& v, int target) {
    vector<vector<int>> res;
    if(v.size()==0)return res;
    int n=v.size();
    Node*a=new Node[n*n/2];
    sort(v.begin(),v.end());

    memset(a,0,sizeof(a));

    int cnt=0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            
            a[cnt++]=Node(i,j,v[i]+v[j]);
        }
    }
    std::sort(a,a+cnt);
    

    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            Node t=Node(-1,-1,target-(v[i]+v[j]));

            auto tar=equal_range(a,a+cnt,t);
            for(auto p=tar.first; p!=tar.second; p++){
                if(p->x > j){
                    vector<int> tmp{v[i],v[j],v[p->x],v[p->y]};
                    res.push_back(tmp);
                    
                }
            }
        }
    }
```
