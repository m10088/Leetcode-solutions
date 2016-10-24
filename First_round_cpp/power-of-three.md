```c++
#include<math.h>
class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n==0)return false;
        int tar=(log(n)/log(3)+0.5);
        cout<<tar<<endl;
        return int(pow(3,tar))==n;
    }
}
```
