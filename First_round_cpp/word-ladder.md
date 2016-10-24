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


int BFS() {
    deque<int> pq;
    pq.push_back(sp);
    dp[sp] = 1;
    while (pq.size()!=0) {
        int fro = pq.front();
        if (fro == tp) return dp[fro];
        pq.pop_front();
        for (int i=0; i<G[fro].size(); i++) {
            int tar = G[fro][i];
            if (dp[tar]==-1) {
                dp[tar] = dp[fro] + 1;
                pq.push_back(tar);
            }
        }
    }
    return 0;
}


void init() {
    for (int i=0; i<N; i++) G[i].clear();
    memset(dp, -1, sizeof(dp));
```
