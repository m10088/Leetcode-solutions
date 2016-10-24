```c++
#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <map>
#include <cmath>
#include <queue>
#include <set>
#include <algorithm>
#define INF 0x3f3f3f3f
#define N (10007)
using namespace std;

vector<int> G[N];
vector<int> fa[N];
vector<vector<string> > res;
int sp, tp;
int dp[N];
int n;
bool can(string & s1, string &s2) {
    int cnt = 0;
    for (int i=0; i<s1.size(); i++) {
        if (s1[i]!=s2[i]) cnt++;
        if (cnt == 2) return false;
    }
    return cnt == 1;
}


void dfs(int i, vector<string> &v, vector<string>& tmp, int depth) {
    tmp[depth] = v[i];
    int n = fa[i].size();
    if (n==0) {
        res.push_back(vector<string>(tmp.begin(), tmp.begin() + depth + 1));
        return;
    }
    for (int k=0; k<fa[i].size(); k++) {
        dfs(fa[i][k], v, tmp, depth+1);
    }
}

void getans(vector<string> &v) {
    vector<string> tmp;
    tmp.resize(100);
    if (fa[tp].size()!=0)
        dfs(tp, v, tmp, 0);
}


void BFS() {
```
