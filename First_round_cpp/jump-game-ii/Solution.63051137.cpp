class Solution {
public:
    int jump(vector<int>& A) {
        int n = A.size();
        int ret = 0;//ç®åä¸ºæ­¢çjumpæ°é
        int curMax = 0;//ä»0~iè¿i+1ä¸ªAåç´ ä¸­è½è¾¾å°çæå¤§èå´
        int curRch = 0;//ä»A[0]è¿è¡retæ¬¡jumpä¹åè¾¾å°çæå¤§èå´
        for(int i = 0; i < n; i ++)
        {
            if(curRch < i)
            {
                ret ++;
                curRch = curMax;
            }
            curMax = max(curMax, A[i]+i);
        }
        return ret;
    }
};