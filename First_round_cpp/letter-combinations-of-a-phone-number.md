```c++
char m[10][4]= {
    {'@','@','@','@'},
    {'@','@','@','@'},
    {'a','b','c','#'},
    {'d','e','f','#'},
    {'g','h','i','#'},
    {'j','k','l','#'},
    {'m','n','o','#'},
    {'p','q','r','s'},
    {'t','u','v','#'},
    {'w','x','y','z'},
};

void dfs(vector<string>&final, const string& s, string& res, int cur) {
    if (cur == s.size()) {
        final.push_back(string(res.begin(), res.begin() + cur));
        return;
    }
    if (s[cur] == '9'||s[cur] == '7') {
        for (int i = 0; i < 4; i++) {
            res[cur] = m[s[cur] - '0'][i];
            dfs(final, s, res, cur + 1);
        }
        }else{
        for (int i = 0; i < 3; i++) {
            res[cur] = m[s[cur] - '0'][i];
            dfs(final, s, res, cur + 1);
        }
    }
}
class Solution {
    public:
        vector<string> letterCombinations(string digits) {
            vector<string> res;
            if (digits.size() == 0)return res;
            string tmp;
            tmp.resize(107);

            dfs(res, digits, tmp, 0);
            return res;
        }
}
```
