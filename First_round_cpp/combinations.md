```c++
void dfs(vector<vector<int>>&final,const vector<int>& v, vector<int>&tmp, int cur,int depth, int n,int k){
    if(depth==k){
        final.push_back(vector<int>(tmp.begin(),tmp.begin()+depth));
        return;
    }
    if(cur==n)return;
    tmp[depth]=v[cur];
    dfs(final,v,tmp,cur+1,depth+1,n,k);
    
    dfs(final,v,tmp,cur+1,depth,n,k);
}


class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> tmp;
        tmp.resize(1007);
        vector<int>v;
        for(int i=1;i<=n;i++){
            v.push_back(i);
        }
        dfs(res,v,tmp,0,0,n,k);
        return res;
    }
}
```
