```c++
#define N 5007
#include <bits/stdc++.h>
using namespace std;
int n, m;
int vis[100][100];
vector<string> ret;


class TrieNode {
    public:
        
        TrieNode() { for (int i = 0; i < 26; i++) a[i] = NULL; flag = false; }

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
            if (root->a[s[cur] - 'a'] == NULL) root->a[s[cur] - 'a'] = new TrieNode();
            if (cur + 1 == s.size()) root->a[s[cur] - 'a']->flag = true;
            else insert_aid(root->a[s[cur] - 'a'], s, cur + 1);

        }

        
        bool search(string word) {
            return search_aid(root, word, 0);
        }

        bool search_aid(TrieNode* root, string &s, int cur) {
            if (root->a[s[cur] - 'a'] == NULL) return false;
            else {
                if (cur + 1 == s.size()) return root->a[s[cur] - 'a']->flag;
                return search_aid(root->a[s[cur] - 'a'], s, cur + 1);
            }
        }
        
        
```
