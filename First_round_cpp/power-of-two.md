```c++
#include<cmath>
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n==1)return true;
        while(n)
        {
            if(n%2)break;
            n=n/2;
        }
        if(n==1)return true;
        else return false;
    }
}
```
