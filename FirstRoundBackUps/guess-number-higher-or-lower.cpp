// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);
#define INF 0x7fffffff


class Solution {
public:
    int guessNumber(int n) {
        long long l = -(INF + 1), r = INF, mid;
        while (l + 1 <r) {
            mid = (l+r) >> 1;
            if (guess(mid)==0) return mid;
            else if (guess(mid)==1) l = mid;
            else                    r = mid;
        }
        return r;
    }
};