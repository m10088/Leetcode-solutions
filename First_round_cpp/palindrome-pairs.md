```c++
#define N 1007

unordered_map<string, vector<int >> lefter1;

unordered_map<string, vector<int >> righter2;


bool isp(const string&s) {
    if (s.size() == 0)return true;
    int p = 0, q = s.size() - 1;
    while (p < q) {
        if (s[p] == s[q]) {
            p++,q--;
            }else{
            return false;
        }
    }
    return true;
}

int cnt;
class Solution {
    public:
        vector<vector<int >> palindromePairs(vector<string>& v) {
            vector<vector<int >> res;
            lefter1.clear(),righter2.clear(),cnt = 0;
            if (v.size() == 0)return res;
            for (int i = 0; i < v.size(); i++) {
                
                string &s = v[i];
                const string& rs = string(s.rbegin(), s.rend());

                
                
                for (auto j = s.end(); j>=s.begin();j--) {
                    if (isp(string(j, s.end()))) {

                        lefter1[string(s.begin(), j)].push_back(i);
                    }
                }

                
                for (auto j = s.begin(); j<=s.end(); j++) {
                    if (isp(string(s.begin(), j))) {

                        righter2[string(j, s.end())].push_back(i);
                    }
                }

            }
```
