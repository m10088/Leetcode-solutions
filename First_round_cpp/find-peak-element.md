```c++
class Solution {
    public:
        int findPeakElement(vector<int>& a) {
            int n = a.size();
            if (n == 1)return 0;
            int lo = 0, hi = n - 1;
            while (1) {
                if (lo + 1 == hi) {
                    if (a[lo] > a[hi])return lo;
                    else return hi;
                }
                auto mid = lo + (hi - lo) / 2;


                if (a[mid] > a[mid - 1] && a[mid] > a[mid + 1]) {
                    return mid;
                    }else if(a[mid+1]>a[mid-1]){
                    lo = mid;
                    }else{
                    hi = mid;
                }

            }
            return lo;
        }
}
```
