```c++
#define INF 0x3f3f3f3f

int isprefix(const string&s, const string&t) {
    for (int i = 0; i < t.size(); i++) {
        if (s[i] != t[i])
            return i;
    }
    return t.size();
}
class Solution {
    public:
        string longestCommonPrefix(vector<string>& strs) {
            if (strs.size() == 0)return string();
            if (strs.size() == 1)return strs[0];
            int miner = INF, index = -1;
            for (int i = 0; i < strs.size(); i++) {
                if (strs[i].size() < miner) {
                    miner = strs[i].size();
                    index = i;
                }
            }
            miner = INF;
            for (int i = 0; i < strs.size(); i++) {
                if (i != index) {
                    miner = std::min(miner, isprefix(strs[i], strs[index]));
                }
            }
            return string(strs[index].begin(), strs[index].begin() + miner);
        }
}
```
