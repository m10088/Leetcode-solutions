```c++
class Solution {
    public:
        vector<vector<int >> subsets(vector<int>& v) {
            
            vector<vector<int> > res;

            int sz = v.size();
            for (int i = 0; i < 1 << sz; i++) {
                vector<int> path;
                for (int j = 0; j != sz; j++) {
                    if (i&(1 << j)) {
                        path.push_back(v[j]);
                    }
                    std::sort(path.begin(), path.end());
                }
                res.push_back(path);

            }
            return res;
        }
}
```
