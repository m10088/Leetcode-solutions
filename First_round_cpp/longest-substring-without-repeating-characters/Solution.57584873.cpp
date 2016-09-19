#include<map>
class Solution {
public:
    //è§£å³æ¹æ¡ï¼å©ç¨ä¸¤ä¸ªæéï¼ä½¿ç¨mapï¼è¿è¡hashï¼å®éä¸è¿æ¯acméé¢çå°ºåæ³
    int lengthOfLongestSubstring(string s) {
        if(s.size()==0)return 0;
        if(s.size()==1)return 1;
        map<char,int> m;//è¡¨ç¤ºåºç°çæ¬¡æ°
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
};