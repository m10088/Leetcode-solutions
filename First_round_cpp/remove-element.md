```c++
class Solution {
    public:
        int removeElement(vector<int>& nums, int val) {
            for (auto p = nums.begin(); p != nums.end();) {
                if ((*p) == val) {
                    p = nums.erase(p);
                }
                else
                    p++;
            }
            return nums.size();
        }
}
```
