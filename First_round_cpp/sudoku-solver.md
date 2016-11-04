```c++
int sum = 0;
pair<int, int> be(int x) {
    if (x>=0 && x<=2)return pair<int, int> (0, 2);
    if (x>=3 && x<=5)return pair<int, int> (3, 5);
    if (x>=6 && x<=8)return pair<int, int> (6, 8);
}
pair<int, int> next_blank(int x, int y, vector<vector<char>>& a) {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (((i == x && j>=y) || i > x) && a[i][j] == '.')
                return pair<int, int> (i, j);

        }
    }
    return pair<int, int> ( - 1, -1);
}

bool dfs(int depth, int x, int y, vector<vector<char>>& a) {

    if (depth == sum + 1)return true;
    bool have[9]; 
    memset(have, 0, 9 * sizeof(bool));
    
    for (int i = 0; i < 9; i++) {
        if (a[x][i] != '.')
            have[a[x][i]-49] = true;
    }
    
    for (int j = 0; j < 9; j++) {
        if (a[j][y] != '.')
            have[a[j][y]-49] = true;
    }

    
    for (int i = be(x).first; i<=be(x).second; i++) {
        for (int j = be(y).first; j<=be(y).second; j++) {
            if (a[i][j] != '.')
                have[a[i][j]-49] = true;
        }
    }

    bool flag = false;

    for (int i = 0; i < 9; i++) {
        if (have[i] == false) {
            a[x][y] = i + 49;
            pair<int, int> next = next_blank(x, y, a);
            if (dfs(depth + 1, next.first, next.second, a)) {
                flag = true;
                break;
```
