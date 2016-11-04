```c++
class Solution {
    public:
        string removeDuplicateLetters(string s) {
            cout << s << endl;
            if (s.size() == 0) return s;
            map<char, int> mp;
            for (int i = 0; i < s.size(); i++) {
                mp[s[i]]++;
            }

            char miner = 'z' + 1;
            int pos = -1;
            for (int i = 0; i < s.size(); i++) {
                if (s[i] < miner) {
                    miner = s[i];
                    pos = i;
                }
                if (mp[s[i]] == 1) {
                    string tmp = s.substr(pos + 1);
                    for (auto p = tmp.begin(); p != tmp.end();) {
                        if ((*p) == miner) p = tmp.erase(p);
                        else p++;
                    }
                    return miner + removeDuplicateLetters(tmp);
                    } else {
                    mp[s[i]]--;
                }
            }
            return "";
        }
}
```
