```c++
#include<cmath>
class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> res(int(pow(2,n)));
        res[0]=0;
        if(n==0){
            return vector<int>{0};
        }
        int round=0,index=0;
        while(round<n){
            int offset=index;
            for(int i=0;i<(1<<round);i++){
                
                index++;
                res[index]=res[offset--]+(1<<round);
            }
            round++;
        }
        return res;
        
    }
}
```
