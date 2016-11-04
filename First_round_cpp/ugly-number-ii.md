```c++
class Solution {
    public:
        
        
        int nthUglyNumber(int n) {
            vector<int> res{0,1,2,3,4,5};
            if (n<=5)return res[n];
            for (int i = 6; i<=n; i++) {
                vector<int>::iterator a,b,c;
                auto two_begin = lower_bound(res.begin(), res.end(), res[res.size() - 1] / 2-1);
                auto three_begin = lower_bound(res.begin(), res.end(), res[res.size() - 1] / 3-1);
                auto five_begin = lower_bound(res.begin(), res.end(), res[res.size() - 1] / 5-1);

                for (a = two_begin; (*a) * 2<=res[res.size() - 1]; a++){}
                for (b = three_begin; (*b) * 3<=res[res.size() - 1]; b++){}
                for (c = five_begin; (*c) * 5<=res[res.size() - 1]; c++){}
                res.push_back(std::min(*a * 2, (std::min(*b * 3, *c * 5))));
            }
            return res[n];
        }
}
```
