```c++

#define N 1007

string a[N];
vector<string> ret;
map<string, int> mp;
vector<int> G[N];
int vis[N][N];
int cur;

int get(string s) {
    if (mp.find(s) == mp.end()) {
        mp[s] = cur;
        a[cur] = s;
        cur++;
        return cur - 1;
        } else {
        return mp[s];
    }
}

bool cmp(int i, int j) { return a[i] < a[j]; }

void euler(int u) {

    for (int i = 0; i < G[u].size(); i++) {
        if (vis[u][G[u][i]] != 0) {
            vis[u][G[u][i]]--;
            euler(G[u][i]);
            ret.push_back(a[G[u][i]]);
            ret.push_back(a[u]);
        }
    }

}


void init() {
    for (int i = 0; i < N; i++) { a[i] = ""; G[i].clear(); }
    mp.clear();
    cur = 0;
    ret.clear();
    memset(vis, 0, sizeof(vis));
}
class Solution {
    public:
        vector<string> findItinerary(vector<pair<string, string >> v) {
            init();
            for (int i = 0; i < v.size(); i++) {
                int v0 = get(v[i].first);
```
