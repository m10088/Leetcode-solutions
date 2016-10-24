```c++
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int flag=0;
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]<nums[i+1]){
                flag=1;
                break;
            }
        }
        if(flag){
            std::next_permutation(nums.begin(),nums.end());
        }else{
            std::sort(nums.begin(),nums.end());
        }
    }
}
```
