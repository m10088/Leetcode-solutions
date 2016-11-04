```c++
#define INF 0x3f3f3f3f
int dx[4]={0, 1, 0, -1};
int dy[4]={1, 0, -1, 0};

class Solution {
    public:
        vector<int> spiralOrder(vector<vector<int>>& v) {
            vector<int> res;
            if (v.size() == 0) return res;
            int n = v.size();
            int m = v[0].size();
            int cnt = 0, x = 0, y = -1;
            while (1) {
                int flag = 0;
                while (y + dy[0] < m && v[x + dx[0]][y + dy[0]] != INF) {
                    res.push_back(v[x + dx[0]][y + dy[0]]);
                    v[x + dx[0]][y + dy[0]] = INF;
                    cnt++;
                    if (cnt == n * m){flag = 1;
                        break;
                    }
                    y = y + dy[0];
                }
                if (flag)break;
                while (x + dx[1] < n && v[x + dx[1]][y + dy[1]] != INF) {
                    res.push_back(v[x + dx[1]][y + dy[1]]);
                    v[x + dx[1]][y + dy[1]] = INF;
                    cnt++;
                    if (cnt == n * m){flag = 1;
                        break;
                    }
                    x = x + dx[1];
                }
                if (flag)break;
                while (y + dy[2]>=0 && v[x + dx[2]][y + dy[2]] != INF) {
                    res.push_back(v[x + dx[2]][y + dy[2]]);
                    v[x + dx[2]][y + dy[2]] = INF;
                    cnt++;
                    if (cnt == n * m){flag = 1;
                        break;
                    }
                    y = y + dy[2];
                }
                if (flag)break;
                while (x + dx[3]>=0 && v[x + dx[3]][y + dy[3]] != INF) {
                    res.push_back(v[x + dx[3]][y + dy[3]]);
                    v[x + dx[3]][y + dy[3]] = INF;
                    cnt++;
                    if (cnt == n * m){flag = 1;
                        break;
```
