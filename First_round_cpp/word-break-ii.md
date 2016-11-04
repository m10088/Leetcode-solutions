```c++

#define N 207
vector<int> G[N];
void genTable(string &s, unordered_set<string> &dict) {
    int n = s.length();
    for (int i = n - 1; i >= 0; i--) {
        if (dict.count(s.substr(i))) G[i].push_back(n);
    }
    for (int i = n - 2; i >= 0; i--) {
        if (!G[i + 1].empty()) {
            for (int j = i, d = 1; j >= 0 ; j--, d++) {
                if (dict.count(s.substr(j, d))) G[j].push_back(i + 1);
            }
        }
    }
    return ;
}

void dfs_ans(const string& s, vector<string>&ans, string tmp, int cur, int former) {

    tmp = tmp + " " + string(s.begin() + former, s.begin() + cur) ;
    if (cur == s.size()) {
        ans.push_back(tmp);
        return;
    }
    for (int i = 0; i < G[cur].size(); i++) {
        dfs_ans(s, ans, tmp, G[cur][i] , cur);
    }
}

void init() {
    for (int i = 0; i < N; i++) {
        G[i].clear();
    }
}

class Solution {
    public:
        vector<string> wordBreak(string s, unordered_set<string>& d) {
            vector<string> ans;
            int n = s.size();
            if (!n)return ans;
            init();
            genTable(s, d);
            string tmp = "";
            dfs_ans(s, ans, tmp, 0, 0);
            for (int i = 0; i < ans.size(); i++) {
                ans[i].erase(0, 2);
            }
            return ans;
```
