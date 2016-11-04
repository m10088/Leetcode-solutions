```c++



int guess(int num);
#define INF 0x7fffffff


class Solution {
    public:
        int guessNumber(int n) {
            long long l = - (INF + 1), r = INF, mid;
            while (l + 1 < r) {
                mid = (l + r) >> 1;
                if (guess(mid) == 0) return mid;
                else if (guess(mid) == 1) l = mid;
                else r = mid;
            }
            return r;
        }
}
```
