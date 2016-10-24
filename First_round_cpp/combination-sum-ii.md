```c++
void dfs(vector<vector<int>>&final, vector<int>&v, vector<int>&tmp, int cur, int sum,int target,int depth){
    if(sum==target){
        vector<int> ans(tmp.begin(),tmp.begin()+depth);
        std::sort(ans.begin(),ans.end());
        final.push_back(ans);
        return;
    }else if(sum>target){
        return;
    }else{
        if(cur==v.size())return;
        tmp[depth]=v[cur];
        
        dfs(final,v,tmp,cur+1,sum+v[cur],target,depth+1);
        
        dfs(final,v,tmp,cur+1,sum,target,depth);
    }
}
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>>res;
        vector<int> tmp(107);
        dfs(res,candidates,tmp,0,0,target,0);
        std::sort(res.begin(),res.end());
        auto new_end=unique(res.begin(),res.end());
        res.erase(new_end,res.end());
        return res;
    }
}
```
