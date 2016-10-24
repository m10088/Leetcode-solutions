```c++
#include<algorithm>
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        auto p=unique(nums.begin(),nums.end());
        nums.erase(p,nums.end());
        return nums.size();
    }
}
```
