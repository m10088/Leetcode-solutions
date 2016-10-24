```c++
class Solution {
public:
    int climbStairs(int n) {
        long x = 0, y = 1;
     for (int j = 0; j < n; j++)
     {
         y = x + y;
         x = y - x;
     }
     return y;
    }
}
```
