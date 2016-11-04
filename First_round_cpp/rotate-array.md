```c++
#include<algorithm>
class Solution {
    public:
        void rotate(vector<int>& v, int m) {
            int n = v.size();
            vector<int> res(n);
            int k = m%n;

            std::copy(v.end() - k, v.end(), res.begin());
            std::copy(v.begin(), v.begin() + n - k, res.begin() + k);
            v = res;
        }
}
```
