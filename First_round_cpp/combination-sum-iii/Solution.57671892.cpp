void dfs(vector<vector<int>>&final, vector<int>&v, vector<int>&tmp, int cur, int sum,int target,int depth,int limit){
    if(sum==target&&depth==limit){
        final.push_back(vector<int>(tmp.begin(),tmp.begin()+depth));
        return;
    }else if(sum>target){
        return;
    }else{
        if(cur==v.size())return;
        tmp[depth]=v[cur];
        //éæ©è¿ä¸ªèç¹
        dfs(final,v,tmp,cur+1,sum+v[cur],target,depth+1,limit);
        //æèä¸éæ©è¿ä¸ªèç¹
        dfs(final,v,tmp,cur+1,sum,target,depth,limit);
    }
}
class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> canidates{1,2,3,4,5,6,7,8,9};
        vector<vector<int>> res;
        vector<int> tmp(307);
        dfs(res,canidates,tmp,0,0,n,0,k);
        return res;
    }
};