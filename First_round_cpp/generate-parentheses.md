```c++

void dfs(vector<string>&final, string&tmp, int lc, int rc, int n, int depth) {
    if (rc == n + 1 || lc == n + 1)
        return;
    if (depth == n * 2) {
        final.push_back(string(tmp.begin(), tmp.begin() + depth));
    }

    if (rc + 1 > lc) {
        tmp[depth] = '(';
        dfs(final, tmp, lc + 1, rc, n, depth + 1);
        }else{
        tmp[depth] = '(';
        dfs(final, tmp, lc + 1, rc, n, depth + 1);
        tmp[depth] = ')';
        dfs(final, tmp, lc, rc + 1, n, depth + 1);
    }

}
class Solution {
    public:
        vector<string> generateParenthesis(int n) {
            string tmp;
            vector<string> res;
            tmp.resize(307);
            dfs(res, tmp, 0, 0, n, 0);
            return res;
        }
}
```
