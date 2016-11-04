```c++
template < typename T>
T StringTo(const std::string &s) {
    std::stringstream sout;
    sout << s;
    T tmp;
    sout >> tmp;
    return tmp;
}

template < typename T>
std::vector<T> StringToVec(const std::string &s) {
    std::stringstream sout;
    sout << s;
    std::vector<T> res;
    T tmp;
    while (sout >> tmp) {
        res.push_back(tmp);
    }
    return res;
}
class Solution {
    public:
        void reverseWords(string &s) {
            vector<string> res;
            res = StringToVec < string > (s);
            std::reverse(res.begin(), res.end());
            string ans;
            for (int i = 0; i < res.size(); i++) {
                if (i == res.size() - 1) {
                    ans = ans + res[i];
                    }else{
                    ans = ans + res[i] + " ";
                }
            }
            s = ans;
        }
}
```
