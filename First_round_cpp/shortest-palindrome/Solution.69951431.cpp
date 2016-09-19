class Solution {
public:
    string shortestPalindrome(string s) {
        string r = s;
        reverse(r.begin(), r.end());
        string t = s + "#" + r;
        
        //è¿éçpç¸å½äºï¼æä»¬æ±çé£ä¸ªnextæ°ç»
        vector<int> p(t.size(), 0);
        for (int i = 1; i < t.size(); ++i) {
            int j = p[i - 1];
            while (j > 0 && t[i] != t[j]) j = p[j - 1];
            p[i] = (j += t[i] == t[j]);
        }
        
        
        return r.substr(0, s.size() - p[t.size() - 1]) + s;
    }
};