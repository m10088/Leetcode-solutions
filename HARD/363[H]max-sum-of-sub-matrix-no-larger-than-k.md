[原题](https://leetcode.com/problems/max-sum-of-sub-matrix-no-larger-than-k)

题意

题解

```C++
class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& v, int target) {
        int ret = -(0x3f3f3f3f);
        int n = v.size();
        if (!n) return 0;
        int m = v[0].size();
        multiset<int> st;
        
        vector<int> sum(m+1);
        vector<int> tmp(m+1);
        for (int i=0; i<n; i++) { 
            for (int k=0; k<m+1; k++) tmp[k] = 0; 
            
            for (int j=i; j<n; j++) {
                for (int k=0; k<m+1; k++) sum[k] = 0; 
                st.clear();
                st.insert(sum[0]);
                
                for (int k=0; k<m; k++) {
                    tmp[k] = tmp[k] + v[j][k];
                    sum[k+1] = sum[k] + tmp[k];
                    
                    
                    auto iter = st.lower_bound(sum[k+1]-target);
                    if (iter != st.end()) {
                        ret = max(ret, sum[k+1]-(*iter));
                    }
                    st.insert(sum[k+1]);
                }
            }    
        }
        
        return ret;
    }
};
```