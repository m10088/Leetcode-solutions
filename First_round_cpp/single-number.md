```c++
#include<algorithm>
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        if(nums.size()==1)
            return nums[0];
        else
        {
            int res=nums[0];
            for(auto p=nums.begin()+1;p!=nums.end();p++)
            {
                 res=res^(*p);
            }
            return res;
        }
    }
}
```
