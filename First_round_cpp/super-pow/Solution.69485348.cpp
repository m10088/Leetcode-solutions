#define M 1337
typedef long long ll; 
long long quickmod(long long a,long long b,long long m) {  
    long long ans = 1;  
    while(b)//ç¨ä¸ä¸ªå¾ªç¯ä»å³å°å·¦ä¾¿å©bçææäºè¿å¶ä½  
    {  
        if(b&1)//å¤æ­æ­¤æ¶b[i]çäºè¿å¶ä½æ¯å¦ä¸º1  
        {  
            ans = (ans*a)%m;//ä¹å°ç»æä¸ï¼è¿éaæ¯a^(2^i)%m  
            b--;//æè¯¥ä¸ºå0  
        }  
        b/=2;  
        a = a*a%m;  
    }  
    return ans;  
}  

ll dp[M];
//é¢å¤çä¸ä¸ a ^ (10 ^ n)æ¯å¤å°
void pre(ll a) {
    memset(dp, 0, sizeof(dp));
    dp[0] = a  % M;
    for (int i=1; i<M; i++) {
        dp[i] = quickmod(dp[i-1], 10, M);
    }
}




ll fx(ll a, ll x, ll n) { //è®¡ç® x * 10 ^ nçå¿«éå¹æ¯å¤å°
    return quickmod(dp[n], x, M);
}


class Solution {
public:
    ll superPow(ll a, vector<int>& b) {
        pre(a);
        ll ans = 1;
        int n = b.size();
        for (int i=0; i<n; i++) {
            ans = (ans * (fx(a, b[i], n-1-i))) % M;
        }
        return ans;
        
    }
};