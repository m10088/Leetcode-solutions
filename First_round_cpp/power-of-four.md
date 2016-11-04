```c++
class Solution {
    public:
        bool isPowerOfFour(int num) {
            if (num == 0)return false;
            return pow(4, int(log(num) / log(4))) == num;
        }
}
```
