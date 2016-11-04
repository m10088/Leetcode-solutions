```c++
template < typename T>
T StringTo(const std::string &s) {
    std::stringstream sout;
    sout << s;
    T tmp;
    sout >> tmp;
    return tmp;
}
bool ok(const string & s) {
    
    if (s[0] == '0') {
        if (s.size() == 1) return true;
        else return false;
    }
    int tmp = StringTo < int > (s);
    if (tmp>=0 && tmp <=255) return true;
    return false;
}

vector<vector<string> > finaler;

void dfs(const string& s, int depth, int cur, vector<string> &tmp) {
    if (depth == 4 && cur == s.size()) {
        finaler.push_back(tmp);
    } else if (depth == 4 ||  cur == s.size()) return;
    else {
        for (int j = cur + 1; j<=cur + 3 && j <= s.size(); j++) {
            string t = string(s.begin() + cur, s.begin() + j);
            if (ok(t)) {
                tmp[depth] = t;
                dfs(s, depth + 1, j, tmp);
            }
        }
    }
}
class Solution {
    public:
        vector<string> restoreIpAddresses(string s) {
            finaler.clear();
            vector<string> tmp;
            tmp.resize(4);
            vector<string> ret;
            dfs(s, 0, 0, tmp);

            
            for (int i = 0; i < finaler.size(); i++) {
                string ans;
                for (int j = 0; j < 3; j++) {
                    ans += finaler[i][j];
                    ans += ".";
```
