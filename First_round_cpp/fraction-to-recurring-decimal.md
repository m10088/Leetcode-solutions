```c++
template < typename T>

std::string ToString(T x) {
    std::stringstream sout;
    sout << x;
    return sout.str();
}
class Solution {
    public:
        string fractionToDecimal(long long n, long long d) {
            string res;
            if (n < 0 && d < 0){n=-n, d=-d; }
            else if (n < 0 && d > 0){n=-n;res.push_back('-');}
            else if (n > 0 && d < 0){d=-d;res.push_back('-');}

            unordered_map<long long, bool> used;

            long long fir = n / d;

            n = n%d;

            res += ToString(fir);
            if (n == 0)return res;

            used[0] = 1;

            int sec = n;
            while (1) {
                if (used.find(sec) == used.end()) {
                    used[sec] = 1;
                    }else{break;}
                sec = sec * 10%d;
            }



            if (sec == 0) {
                res.push_back('.');
                int flag = 0;
                auto last = n / d,begin = n%d;
                while (1) {
                    if (flag == 0){flag = 1;}
                    else res.push_back(last + 48);
                    last = begin * 10 / d;
                    begin = begin * 10%d;
                    if (begin == 0) {
                        res.push_back(last + 48);
                        break;
                    }
                }
```
