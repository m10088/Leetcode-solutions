#define INF 0x3f3f3f3f
class Solution {
public:
    int firstMissingPositive(vector<int>& a) {
        //ç®åççæ¬ï¼åæé¡ºåºç¶åå¯»æ¾
        int n = a.size();
        
        sort(a.begin(), a.end());
       
        int cnt = 0;
        for (int i=0; i<n; i++) {
            if (a[i] > 0 && i==0 || a[i] > 0 && a[i]!=a[i-1] ) {
                cnt++;
                if (a[i]!=cnt) return cnt;
            }
        }
        return cnt+1;
    
        
    }
};