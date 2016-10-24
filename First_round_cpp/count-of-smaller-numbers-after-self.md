```c++
#define N 10007
int bit[N];
unordered_map<int,int> tr;
void update(int x,int val){  
    for(;x<N;x+=x&-x)  
        bit[x]+=val;  
}  
int query(int x){  
    int res=0;  
    for(;x;x-=x&-x)  
        res+=bit[x];  
    return res;  
}
void Init(){
    memset(bit,0,sizeof(bit));
    tr.clear();
}
void Discrete(const vector<int>&v){
    vector<int> tmp(v.size());
    copy(v.begin(),v.end(),tmp.begin());
    sort(tmp.begin(),tmp.end());
    int cnt=2;
    for(int i=0;i<tmp.size();i++){
        if(tr.find(tmp[i])==tr.end()){
            tr[tmp[i]]=cnt++;
        }
    }
    cout<<"--"<<cnt<<endl;
}
class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        cout<<nums.size()<<endl;
        vector<int> res(nums.size());
        if(nums.size()==0)return res;
        Init();
        Discrete(nums);
        int x;
        for(int i=nums.size()-1;i>=0;i--){
            x=tr[nums[i]];
            res[i]=query(x-1);
            update(x,1);
        }
        return res;
    }
}
```
