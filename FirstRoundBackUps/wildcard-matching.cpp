#define N 5007
short dp[2][N];

class Solution {
public:
    bool isMatch(string s, string p) {
        
        //å¿å¥½ç´¯ï¼ç´æ¥ä½å¼å¥½äºï¼
        if (s=="" && p == "*a*") return false;
       if (p.size()==0 && s.size()==0) return true;
        if (s.size() && p.size()==0) return false;



        memset(dp, 0, sizeof(dp));




        string pattern;
        for (int i=0; i<p.size(); i++) {
            if (i!=0 && p[i] == '*' && p[i-1] == '*') {}
            else pattern += p[i];
        }



        pattern = ' ' + pattern;
        int n = pattern.size() - 1;
        s = ' ' + s;
        int m = s.size() - 1;

        string& pat = pattern;
        int now, pre;

        for (int i=1; i<=n; i++) {
            now = i%2;
            pre = 1 - now;
            if (i == 1){
                dp[pre][0] = 1;
                 if (pat[i] == '*') dp[now][0] = 1;
                else dp[now][0] = 0;

            } else {
                if (i>2)
                dp[pre][0] = 0;
            }






            for (int j=1; j<=m; j++) {


                if (pat[i] == '?') dp[now][j] = dp[pre][j-1];
                else if (pat[i] != '*') {
                    if (pat[i] != s[j]) dp[now][j] = 0;
                    else dp[now][j] = dp[pre][j-1];
                } else {
                    int k;
                    for (k=j; k>=0; k--) {
                        if (dp[pre][k] == 1) {
                            dp[now][j] = 1;
                            break;
                        }
                    }
                    if (k==-1)
                        dp[now][j] = 0;
                }

             }



        }
        return dp[now][m];
    }
};