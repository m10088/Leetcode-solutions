```c++
#define INF 0x3f3f3f3f
class Solution {
    public:
        
        int maxProduct(vector<int>& nums) {
            int n = nums.size();
            if (n == 0)return 0;

            int *max = new int[n], *min = new int[n];
            max[0] = nums[0],min[0] = nums[0];
            for (int i = 1; i < n; i++) {
                
                int a = nums[i];
                int b = max[i - 1] * nums[i];
                int c = min[i - 1] * nums[i];
                max[i] = std::max(a, std::max(b, c));
                min[i] = std::min(a, std::min(b, c));
            }
            int maxer=-INF;
            for (int i = 0; i < n; i++) {
                maxer = std::max(maxer, max[i]);
            }
            return maxer;
        }
}
```
