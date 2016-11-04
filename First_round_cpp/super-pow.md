```c++
#define M 1337
typedef long long ll;
long long quickmod(long long a, long long b, long long m) {
    long long ans = 1;
    while (b) {
        if (b&1) {
            ans = (ans * a)%m;
            b--;
        }
        b /= 2;
        a = a * a%m;
    }
    return ans;
}

ll dp[M];

void pre(ll a) {
    memset(dp, 0, sizeof(dp));
    dp[0] = a % M;
    for (int i = 1; i < M; i++) {
        dp[i] = quickmod(dp[i - 1], 10, M);
    }
}




ll fx(ll a, ll x, ll n) { 
    return quickmod(dp[n], x, M);
}


class Solution {
    public:
        ll superPow(ll a, vector<int>& b) {
            pre(a);
            ll ans = 1;
            int n = b.size();
            for (int i = 0; i < n; i++) {
                ans = (ans * (fx(a, b[i], n - 1 - i))) % M;
            }
            return ans;

        }
}
```
