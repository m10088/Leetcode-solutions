```c++
bool contains(vector<int>&nums,int lo,int hi){
    int ans=0;
    for(int i=0;i<nums.size();i++){
        if(nums[i]<=hi&&nums[i]>=lo){
            ans++;
        }
    }
    if(ans<=hi-lo+1)return false;
    else return true;
}
int recur(vector<int>&nums,int lo,int hi){
    if(lo==hi)return lo;
    int mid=lo+(hi-lo)/2;
    if(contains(nums,lo,mid)) return recur(nums,lo,mid);
    else return recur(nums,mid+1,hi);
}
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        
        int lo=1,hi=nums.size()-1;
        return recur(nums,lo,hi);
    }
}
```
