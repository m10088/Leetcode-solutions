```c++
class Solution {
public:
    int findMin(vector<int>& nums) {
        if(nums.size()==1)return nums[0];
        if(nums[0]<nums[nums.size()-1])return nums[0];
        int left=0,right=nums.size()-1;
        while(left<right){
            auto mid=left+(right-left)/2;
            if(nums[mid]>=nums[0]){
                left=mid+1;
            }else{
                right=mid;
            }
        }
        return nums[left];
    }
};
```
