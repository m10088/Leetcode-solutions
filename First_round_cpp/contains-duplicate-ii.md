```c++
#include<cmath>

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& v, int k) {
        unordered_map<int,int> m;
        if(v.size()==0)
            return false;
        
        for(int i=0;i<v.size();i++){
            auto res=m.find(v[i]);
            if(res==m.end()){
                m[v[i]]=i;
            }else{
                if(i-res->second<=k)
                    return true;
                else{
                    m[v[i]]=i;
                }
            }
        }
        return false;
        
    }
}
```
