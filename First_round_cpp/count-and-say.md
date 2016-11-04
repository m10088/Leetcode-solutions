```c++
string function_(const string&s) {
    auto p = s.begin();
    string res;
    while (p != s.end()) {
        auto next = p + 1;
        while (next != s.end() && (*next) == (*p)) {
            next++;
        }
        res.push_back(next - p + 48),res.push_back(*p);
        p = next;
    }
    return res;
}

class Solution {
    public:
        string countAndSay(int n) {
            string fir = "1";
            for (int i = 1; i < n; i++) {
                fir = function_(fir);
            }
            return fir;
        }
}
```
