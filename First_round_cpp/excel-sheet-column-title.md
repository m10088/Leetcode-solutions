```c++
class Solution {
    public:
        string convertToTitle(long long n) {
            string ans;
            long long tar = n, i;
            for (i = 1; ; i++) {
                tar = tar - pow(26, i);
                if (tar<=0)break;
            }
            tar = tar + pow(26, i);
            tar = tar - 1;
            vector<int> res(i);
            
            int cnt = 0;
            while (tar) {
                res[cnt++] = tar%26;
                tar = tar / 26;
            }
            for (int i = res.size() - 1; i>=0;i--) {
                ans.push_back(65 + res[i]);
            }
            return ans;
        }
}
```
