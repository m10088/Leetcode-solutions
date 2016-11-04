```c++
class Solution {
    public:
        vector<vector<int >> generate(int n) {
            vector<vector<int >> res;
            if (!n)return res;
            vector<int> base={1};
            res.push_back(base);
            if (n == 1)return res;
            for (int k = 2; k<=n; k++) {
                vector<int> layer;
                layer.push_back(1);
                for (int i = 0; i < res.back().size() - 1; i++)
                    layer.push_back(res.back()[i] + res.back()[i + 1]);
                layer.push_back(1);
                res.push_back(layer);

            }
            return res;

        }
}
```
