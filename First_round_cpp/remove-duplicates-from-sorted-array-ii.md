```c++
class Solution {
public:
    int removeDuplicates(vector<int>& v) {
        auto b=v.begin();
        auto e=v.begin();
        int cnt=0;
        vector<int> a;
        while(e!=v.end())
        {
           if((*b)==(*e)&&cnt<2)
           {
               cnt++;
               e++;
           }
           else if((*b)==(*e)&&cnt==2)
           {
               a.push_back(*e);
               e=v.erase(e);
           }
           else
           {
               cnt=0;
               b=e;
           }
        }
        int res=v.size();
        copy(a.begin(),a.end(),back_inserter(v));
        return res;
        
    }
}
```
