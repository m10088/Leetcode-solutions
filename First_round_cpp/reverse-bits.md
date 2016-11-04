```c++
#include<cmath>
class Solution {
    public:
        uint32_t reverseBits(uint32_t n) {
            uint32_t res = 0;
            int buer = -1;
            for (int i = 1; i<=32; i++) {
                buer = n%2;
                res = res + buer * pow(2, 32 - i);
                n = n / 2;
            }
            return res;

        }
}
```
