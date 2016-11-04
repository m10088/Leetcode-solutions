```c++
class Solution {
    public:
        bool containsDuplicate(vector<int>& v) {
            unordered_map<int, int> _hash;
            if (v.empty())return false;
            for (auto i = 0; i < v.size(); i++) {
                if (_hash.find(v[i]) == _hash.end())
                    _hash[v[i]] = i;
                else
                    return true;
            }
            return false;
        }
}
```
