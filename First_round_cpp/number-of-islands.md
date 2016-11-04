```c++
int dx[4]={0, 1, 0, -1};
int dy[4]={1, 0, -1, 0};


bool legal(vector<vector<char>>& v, int i, int j) {
    if (i < v.size() && i>=0 && j < v[0].size() && j>=0)
        return true;
    else
        return false;
}

void dfs(vector<vector<char>>&v, int i, int j) {
    v[i][j] = '0';
    for (int k = 0; k < 4; k++) {
        if (legal(v, i + dx[k], j + dy[k]) && v[i + dx[k]][j + dy[k]] == '1') {
            dfs(v, i + dx[k], j + dy[k]);
        }
    }
}

class Solution {
    public:
        int numIslands(vector<vector<char>>& v) {
            int cnt = 0;
            if (v.size() == 0)return cnt;
            for (int i = 0; i < v.size(); i++) {
                for (int j = 0; j < v[0].size(); j++) {
                    if (v[i][j] == '1') {
                        cnt++;
                        dfs(v, i, j);
                    }
                }
            }
            return cnt;

        }
}
```
