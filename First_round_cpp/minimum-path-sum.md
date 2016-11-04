```c++
class Solution {
    public:
        int minPathSum(vector<vector<int>>& g) {
            const int m = g.size();
            const int n = g[0].size();
            int d[m][n]={1 << 15};
            for (int i = m - 1; i>=0;i--) {
                for (int j = n - 1; j>=0;j--) {
                    if (i == m - 1 && j == n - 1) {
                        d[i][j] = g[i][j];
                    }
                    else if (i == m - 1 && j < n - 1) {
                        d[i][j] = d[i][j + 1] + g[i][j];
                    }
                    else if (i < m - 1 && j == n - 1) {
                        d[i][j] = d[i + 1][j] + g[i][j];
                    }
                    else
                    {
                        d[i][j] = min(d[i + 1][j], d[i][j + 1]) + g[i][j];
                    }
                }
            }
            return d[0][0];
        }
}
```
