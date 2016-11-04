```c++
class Solution {
    public:
        int hIndex(vector<int>& v) {
            if (v.size() == 0)return 0;
            int n = v.size();
            int lo = 0, hi = v.size();
            int res, mid;
            while (lo < hi) {
                mid = lo + (hi - lo) / 2;
                if (v[mid] - (n - mid) < 0) {
                    lo = mid + 1;
                    res = lo;
                    }else{
                    hi = mid;
                    res = hi;
                }
            }
            if (res == n)return 0;
            return n - res;
        }
}
```
