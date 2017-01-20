
#define N 5007
#include <bits/stdc++.h>
using namespace std;
int n,m;
int vis[100][100];
vector<string> ret;


class TrieNode {
public:
    
    TrieNode() { for (int i=0; i<26; i++) a[i]=NULL; flag = false; }

    TrieNode* a[26];
    bool flag; 

};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    
    void insert(string word) { insert_aid(root, word, 0); }


    void insert_aid(TrieNode*& root, string& s, int cur) {
        if (root->a[s[cur]-'a']==NULL) root->a[s[cur]-'a']=new TrieNode();
        if (cur + 1== s.size()) root->a[s[cur]-'a']->flag=true;
        else insert_aid(root->a[s[cur]-'a'], s, cur+1);

    }

    
    bool search(string word) {
        return search_aid(root, word, 0);
    }

    bool search_aid(TrieNode* root,  string &s, int cur) {
        if (root->a[s[cur]-'a']==NULL) return false;
        else{
            if(cur + 1==s.size()) return root->a[s[cur]-'a']->flag;
            return search_aid(root->a[s[cur]-'a'], s, cur+1);
        }
    }
    
    
    bool startsWith(string prefix) {
        return fx_aid(root, prefix, 0);
    }
    bool fx_aid(TrieNode* root, string &s, int cur) {
        if (root->a[s[cur]-'a']==NULL) return false;
        else {
            if(cur + 1==s.size()) return true;
            return fx_aid(root->a[s[cur]-'a'], s, cur+1);
        }
    }

private:
    TrieNode* root;
};


void dfs(vector<vector<char>>& v, Trie &trie, int i, int j, string s) {
    if (i<0 || i>=n ||j < 0 || j>=m) return;
    if (vis[i][j]==true) return;

    vis[i][j] = true;
    string t = s + v[i][j];

    if (trie.startsWith(t)==false) { vis[i][j] = false; return; }
    if (trie.search(t)==true) ret.push_back(t);

    dfs(v, trie, i+1, j, t);
    dfs(v, trie, i-1, j, t);
    dfs(v, trie, i, j+1, t);
    dfs(v, trie, i, j-1, t);

    vis[i][j] = false;


}

class Solution {
public:
    vector<string> findWords(vector<vector<char>>& v, vector<string>& words) {
        memset(vis, 0, sizeof(vis));
        ret.clear();
        n = v.size();
        if (n==0) return ret;
        m = v[0].size();

        Trie trie;
        for (int i=0; i<words.size(); i++) {
            trie.insert(words[i]);
        }
        string tmp ="";
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                dfs(v, trie, i, j, tmp);
            }
        }
        sort(ret.begin(), ret.end());
        ret.erase(unique(ret.begin(), ret.end()), ret.end());
        return ret;
    }
};