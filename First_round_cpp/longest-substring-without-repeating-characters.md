```c++
#include<map>
class Solution {
public:
    
    int lengthOfLongestSubstring(string s) {
        if(s.size()==0)return 0;
        if(s.size()==1)return 1;
        map<char,int> m;
        int ans=-1,fir=0,sec=1;
        m[s[0]]=1;
        while(1){
            auto tmp=m.find(s[sec]);
            if(tmp==m.end()){
                m[s[sec]]=1;
                sec++;
                if(sec==s.size()){
                    ans=std::max(ans,sec-fir);
                    break;
                }
            }else{
                ans=std::max(ans,sec-fir);
                m.erase(s[fir]);
                fir++;
            }
        }
        return ans;
    }
}
```
