```c++
class Solution {  
public:  
    int minPatches(vector<int>& nums, int n) {  
        long long cur=0,k=0,ans=0;
        while(cur<n){
            if(k<nums.size()&&nums[k]<=cur+1){
                cur+=nums[k];
                k++;
            }else{
                ans++;
                cur=2*cur+1;
            }
        }
        return ans;
    }
}; 
```
