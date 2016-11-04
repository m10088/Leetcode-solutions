```c++
class Solution {
    public:
        int majorityElement(vector<int>& nums) {
            vector<int> res = nums;
            while (!res.empty()) {
                int tmp = *res.begin();
                int n = 0;
                for (auto p = res.begin(); p != res.end();) {
                    if (*p == tmp) {
                        n++;
                        if (n > nums.size() / 2)
                            return tmp;
                        else
                            p = res.erase(p);
                    }
                    else p++;
                }
            }
        }
}
```
