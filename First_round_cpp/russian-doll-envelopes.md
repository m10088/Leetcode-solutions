```c++
class Solution {
public:
    int maxEnvelopes(vector<pair<int, int>>& envelopes) {
        vector<int> dp(envelopes.size(), 1);
        sort(envelopes.begin(), envelopes.end());
        int res = 0;
        for (int i = 0; i < envelopes.size(); ++i){
            for (int j = 0; j < i; ++j){
                if (envelopes[i].first > envelopes[j].first && envelopes[i].second > envelopes[j].second)
                    dp[i] = max(dp[i], dp[j] + 1);
            }
            res = max(res, dp[i]);
        }
        return res;
    }
}
```
