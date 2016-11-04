```c++

int G[8][5] = {
    {3, 2, 1, -1, -1},
    {-1, 4, 1, 5, -1},
    {-1, -1, 4, -1, -1},
    {-1, 2, 1, -1, -1},
    {-1, -1, 4, 5, -1},
    {6, -1, 7, -1, -1},
    {-1, -1, 7, -1, -1},
    {-1, -1, 7, -1, -1}
};
map<char, int> mp;

class Solution {
    public:
        bool isNumber(string s) {

            
            int allblank = true;
            for (int i = 0; i < s.size(); i++) {
                if (s[i] != ' ') {
                    allblank = false;
                    break;
                }
            }
            if (allblank)return false;

            int start = s.find_first_not_of(" ");
            int end = s.find_last_not_of(" ");
            s = s.substr(start, end - start + 1);



            mp['+'] = 0;
            mp['-'] = 0;
            mp['.'] = 1;
            mp['e'] = 3;
            for (char i = '0'; i<='9'; i++) mp[i] = 2;
            int state = 0;
            for (int i = 0; i < s.size(); i++) {
                int transfer = 4;
                if (mp.find(s[i]) != mp.end()) transfer = mp[s[i]];
                state = G[state][transfer];
                if (state == -1) return false;
            }
            return state == 1 || state == 4 || state == 7 ;
        }
}
```
