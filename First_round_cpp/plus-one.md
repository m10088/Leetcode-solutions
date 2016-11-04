```c++
#include<algorithm>
class Solution {
    public:
        vector<int> plusOne(vector<int>& v) {
            vector<int> res;
            int j = 1;
            for (int k = v.size() - 1; k>=0;k--) {
                if (v[k] + j == 10) {
                    res.push_back(0);
                    j = 1;

                }
                else
                {
                    res.push_back(v[k] + j);
                    j = 0;
                }
            }
            if (j)
                res.push_back(j);
            reverse(res.begin(), res.end());
            return res;
        }
}
```
