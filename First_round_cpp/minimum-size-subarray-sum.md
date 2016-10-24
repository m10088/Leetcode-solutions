```c++
#define INF 0x3f3f3f3f
class Solution {
public:
    
    int minSubArrayLen(int target, vector<int>& nums) {
        int t=0,s=0,sum=0,ans=INF,flag=0;
        while(1){
            while(t<nums.size()&&sum<target){
                sum+=nums[t++];
            }
            if(sum<target)break;
            if(sum>=target){
                if(t-s<ans){
                    ans=t-s;
                    flag=1;
                }
            }
            sum-=nums[s++];
        }
        if(flag)
            return ans;
        else
            return 0;
    }
}
```
