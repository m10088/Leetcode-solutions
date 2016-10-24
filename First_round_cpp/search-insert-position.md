```c++
#include<algorithm>
class Solution {
public:
    int searchInsert(vector<int>& v, int target) {
      if(v.empty()==true)return 0;
      else
      {
          int i=0;
          while(1)
          {
              if(v[i]<target)
              {
                  if(i==v.size()-1)
                  {
                      return i+1;
                  }
                  else
                  {
                    i++;
                  }
              }
              else if(target==v[i])
              {
                  return i;
              }
              else
              {
                  return i;
              }
              
          }
      }
    }
}
```
