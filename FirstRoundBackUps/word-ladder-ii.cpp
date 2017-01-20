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
    deque<int> pq;
    pq.push_back(sp);
    dp[sp] = 1;
    while (pq.size()!=0) {
        int fro = pq.front();
        pq.pop_front();
        for (int i=0; i<G[fro].size(); i++) {
            int tar = G[fro][i];
            int step = dp[fro] + 1;

            if (dp[tar]==-1) {
                dp[tar] = step;
                fa[tar].push_back(fro);
                pq.push_back(tar);
            } else if (dp[tar] == step) {
                fa[tar].push_back(fro);
                pq.push_back(tar);
            } else if (step > dp[tar]) {}
        }
    }






}


void init() {
    for (int i=0; i<N; i++) { G[i].clear(); fa[i].clear(); }
    memset(dp, -1, sizeof(dp));
    res.clear();
    
 
   
}





class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, unordered_set<string> &wordList) {
         init();

        wordList.insert(beginWord);
        wordList.insert(endWord);
        vector<string> v(wordList.begin(), wordList.end());
    
        n = v.size();
        for (int i=0 ;i<v.size(); i++) {
            if (v[i]==beginWord) sp = i;
            if (v[i]==endWord) tp = i;
            for (int j=i+1; j<v.size(); j++) {
                if (can(v[i], v[j])) {
                    G[i].push_back(j);
                    G[j].push_back(i);
                }
            }
        }
        BFS();
        for (int i=0; i<n; i++){
            sort(fa[i].begin(), fa[i].end());
            fa[i].erase(unique(fa[i].begin(), fa[i].end()), fa[i].end());
        }
        getans(v);
    
        for (int i=0; i<res.size(); i++) {
    
    
    
            reverse(res[i].begin(), res[i].end());
        }
        
        
    
    
    
    
    
    
        return res;
    }
};