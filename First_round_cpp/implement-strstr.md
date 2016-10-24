```c++
class Solution {
public:
    int strStr(string haystack, string needle) {
        int res=haystack.find(needle);
        if(res>haystack.size()-needle.size())return -1;
        else return res;
    }
}
```
