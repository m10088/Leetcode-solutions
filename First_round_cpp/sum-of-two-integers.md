```c++
class Solution {
public:
    int getSum(int a, int b) {
        int c = a & b, r = a ^ b;
        if (c == 0) return r;
        else return getSum(r, c<<1);
    }
}
```
