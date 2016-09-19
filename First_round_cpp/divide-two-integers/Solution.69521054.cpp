#define INF 0x7fffffff
class Solution {
public:
    int divide(long long dividend, long long divisor) {
        if (divisor == 0) return INF;
        else {
            long long ret = dividend / divisor;
            if (ret > INF) return INF;
            else return ret;
        }
    }
};