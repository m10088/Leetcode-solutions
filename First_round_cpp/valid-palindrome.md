```c++
class Solution {
    public:
        bool isPalindrome(string s) {
            
            for (auto p = s.begin(); p != s.end();) {
                if ((*p)>='A'&&(*p)<='Z') {
                    (*p) = (*p) + 32;
                    }else if((*p)>='a'&&(*p)<='z'||(*p)>='0'&&(*p)<='9'){
                    p++;
                    }else{
                    p = s.erase(p);
                }
            }
            int begin = 0, end = s.size() - 1;
            while (begin<=end) {
                if (s[begin] == s[end]) {
                    begin++,end--;
                    }else{
                    return false;
                }
            }
            return true;
        }
}
```
