```c++
/**
* Definition for an interval.
* struct Interval {
    * int start;
    * int end;
    * Interval() : start(0), end(0) {}
    * Interval(int s, int e) : start(s), end(e) {}
    * };
*/
bool cmp(const Interval& v1, const Interval &v2) {
    return v1.start < v2.start;
}
class Solution {
    public:
        vector<Interval> insert(vector<Interval>& a, Interval x) {
            int b = x.start, e = x.end;
            vector<Interval> ret;
            int n = a.size();
            int fir = -1, sec = -1;
            if (n == 0) { ret.push_back(x); return ret; }

            
            
            
                
                    
                    
                    
                
            

            for (int i = 0; i < n; i++) {
                if (a[i].start <= b && b <= a[i].end) {
                    fir = i;
                }
                if (a[i].start <= e && e <= a[i].end) {
                    sec = i;
                }
            }

            
            
            if (fir == -1 && sec == -1) {
                for (int i = 0; i < n; i++) {
                    if (a[i].start > b && a[i].end < e) {}
                    else ret.push_back(a[i]);
                }
                ret.push_back(x);
            }
            
```
