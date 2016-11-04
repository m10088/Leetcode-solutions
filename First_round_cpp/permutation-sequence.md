```c++
template < typename T>

std::string ToString(T x) {
    std::stringstream sout;
    sout << x;
    return sout.str();
}
int fac(int x) {
    if (x == 0 || x == 1) return 1;
    else return x*fac(x - 1);
}

class Solution {
    public:
        string getPermutation(int n, int k) {
            string ans(n, ' ');
            const int sz = n;
            bool vis[sz];
            int i, j, t;
            memset(vis, 0, sizeof(vis));
            --k;
            for (i = 0; i < n; ++i) {
                t = k / fac(n - i - 1);
                for (j = 1; j <= n; j++) {
                    if (!vis[j]) {
                        if (t == 0) break;
                        --t;
                    }
                }
                ans[i] = j + 48, vis[j] = true;
                k %= fac(n - i - 1);
            }
            return ans;
        }
}
```
