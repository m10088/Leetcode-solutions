```c++
#include<string.h>
int dp[1007][1007];
int dfs(int i, int j, const string&s) {
    if (dp[i][j] != -1)return dp[i][j];
    if (i == j || i > j)return dp[i][j] = 1;
    if (s[i] == s[j]) {
        if (dfs(i + 1, j - 1, s)) {
            dp[i][j] = 1;
            return 1;
            }else{
            dfs(i + 1, j, s);
            dfs(i, j - 1, s);
            return dp[i][j] = 0;
        }
        }else{
        dp[i][j] = 0;
        dfs(i, j - 1, s);
        dfs(i + 1, j, s);
        return 0;
    }
}
class Solution {
    public:
        
        string longestPalindrome(string s) {
            memset(dp, -1, sizeof(dp));
            dfs(0, s.size() - 1, s);
            int maxer = -1;
            int res_x = -2, res_y = -1;
            for (int i = 0; i < s.size(); i++) {
                for (int j = i; j < s.size(); j++) {
                    if (dp[i][j] == 1 && j - i > maxer) {
                        res_x = i,res_y = j;
                        maxer = res_y - res_x;
                    }
                }
            }
            return string(s.begin() + res_x, s.begin() + res_y + 1);
        }
}
```
