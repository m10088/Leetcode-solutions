#define N 50007
#define INF 0x3f3f3f3f
int f[N];
int g[N];
class Solution {
public:
    int maxProfit(vector<int>& a) {
        int n = a.size();
        if (n==0) return 0;
        f[0] = 0;
        int miner = a[0];
        for (int i=1; i<=n; i++) {
            
            if (a[i-1] >= miner)
                f[i] = max(a[i-1] - miner, f[i-1]);
            else  {
                f[i] = f[i-1];
                miner = a[i-1];
            }
        }
        g[n] = 0;
        int maxer = a[n-1];
        for (int i=n-1; i>=0; i--) {
            if (a[i] <= maxer) {
                g[i] = max(maxer - a[i], g[i+1]);
            } else {
                g[i] = g[i+1];
                maxer = a[i];
            }
        }
        
        maxer = -INF;
        for (int i=0; i<=n; i++) {
            
            maxer = max(maxer, g[i] + f[i]);
        }
        return maxer;
    }
};