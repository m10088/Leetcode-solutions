class Solution {
public:
    int maxArea(vector<int>& height) {
        /*å·§å¦çä½¿ç¨è´ªå¿ç­ç¥
            å¦æå·¦è¾¹çé«åº¦æ¯å³è¾¹çé«åº¦å°,å°å·¦è¾¹çåå³ç§»å¨ï¼
            åä¹åå·¦ç§»å¨ï¼ä¸ç´å°ä¸¤ä¸ªæéç¸é
        */
        if(height.size()==0||height.size()==1)return 0;
        int fir=0,sec=height.size()-1;
        int ans=-1;
        while(fir<sec){
            ans=std::max((sec-fir)*std::min(height[fir],height[sec]),ans);
            if(height[fir]<height[sec]){
                fir++;
            }else{
                sec--;
            }
        }
        return ans;
    }
};