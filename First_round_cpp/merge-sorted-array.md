```c++
#include<algorithm>

class Solution {
public:
    void merge(vector<int>& v1, int m, vector<int>& v2, int n) {
        vector<int> v(m+n);
       std::merge(v1.begin(),v1.begin()+m,v2.begin(),v2.begin()+n,v.begin());
       std::copy(v.begin(),v.end(),v1.begin());
    }
}
```
