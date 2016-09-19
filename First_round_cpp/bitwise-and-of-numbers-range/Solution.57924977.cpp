class Solution {
public:
    int rangeBitwiseAnd(long long m, long long n) {
        long long ret = 0;
        long long gap = n - m;
        if(gap == 0)
            return m;
        long long bit = 1;
        //intæé«ä½ä¸å®æ¯1ï¼å¿½ç¥
        for(int i = 0; i <= 31; i ++)
        {
            
            //å¤æ­ç¬¬iä½æ¯ä¸æ¯å¨é¨æ¯1
            //mçç¬¬iä½æ¯1ï¼
            long long x=m%(1<<(i+1)),y=n%(1<<(i+1));
            if(x&(1<<i) && y&(1<<i) && (m+(1<<i)-1>=n)){
                ret |= bit;
                
            }
            bit <<= 1;
        }
        return ret;
    }
};