```c++
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


        void insert_aid(TrieNode*& root, const string& s, int cur) {
            if (root->a[s[cur] - 'a'] == NULL) root->a[s[cur] - 'a'] = new TrieNode();
            if (cur + 1 == s.size()) root->a[s[cur] - 'a']->flag = true;
            else insert_aid(root->a[s[cur] - 'a'], s, cur + 1);

        }

        
        bool search(string word) {
            return search_aid(root, word, 0);
        }

        bool search_aid(TrieNode* root, const string &s, int cur) {
            if (root->a[s[cur] - 'a'] == NULL) return false;
            else {
                if (cur + 1 == s.size()) return root->a[s[cur] - 'a']->flag;
                return search_aid(root->a[s[cur] - 'a'], s, cur + 1);
            }
        }
        
        
        bool startsWith(string prefix) {
            return fx_aid(root, prefix, 0);
        }
        bool fx_aid(TrieNode* root, const string &s, int cur) {
            if (root->a[s[cur] - 'a'] == NULL) return false;
            else {
                if (cur + 1 == s.size()) return true;
                return fx_aid(root->a[s[cur] - 'a'], s, cur + 1);
            }
```
