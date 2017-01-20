#define N 307
int dp[N][N];

class Solution {
public:
    int maximalSquare(vector<vector<char>>& v) {
        if(v.size()==0)return 0;
        memset(dp,0,sizeof(dp));
        int n=v.size(),m=v[0].size();
        
        
        int maxer = 0;  
  
        for(int i=0; i<n; i++) {  
            if(v[i][0]=='1') {  
                dp[i][0] = 1;  
                maxer = 1;  
            }  
        }
        for(int j=0; j<m; j++) {  
            if(v[0][j]=='1') {  
                dp[0][j] = 1;  
                maxer = 1;  
            }  
        }  
        for(int i=1; i<n; i++) {  
            for(int j=1; j<m; j++) {  
                if(v[i][j]=='0') dp[i][j]=0;  
                else {  
                    dp[i][j] = std::min(std::min( dp[i-1][j], dp[i][j-1]), dp[i-1][j-1] ) + 1;  
                    maxer = std::max(maxer, dp[i][j]);  
                }  
            }  
        }
        return maxer*maxer;
    }
};