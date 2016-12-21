class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        //å¦ææä»¬ä½¿ç¨éæºçç®æ³æ¥è§£å³è¿ä¸ªé®é¢ï¼é£ä¹å¯è½åºç°ä¸ä¸ªé®é¢ï¼å°±æ¯å¾é¾ç¡®å®æ¯ä¸ä¸ªæ°è¿æ¯ä¸¤ä¸ªæ°
        //å¦æå·²ç»ç¥éæ¯åºç°1æ¬¡ï¼ä½æ¯æä»¬ä»ç¶æç§ä¸¤æ¬¡çç®æ³å»æ¾ï¼å¤æåº¦ä¸å
        vector<int> res;
        vector<int> &v=nums;
        int fir=0,sec=0;
        int firstcounter=0,secondcounter=0;
        for(int i=0;i<v.size();i++){
            if(v[i]==fir)firstcounter++;
            else if(v[i]==sec)secondcounter++;
            else if(firstcounter==0) fir=v[i],firstcounter=1;
            else if(secondcounter==0) sec=v[i],secondcounter=1;
            else firstcounter--,secondcounter--;
        }
        firstcounter=secondcounter=0;
        for(int i=0;i<v.size();i++){
            if(v[i]==fir)firstcounter++;
            else if(v[i]==sec)secondcounter++;
            else {}
        }
        if(firstcounter>(v.size()/3))res.push_back(fir);
        if(secondcounter>v.size()/3)res.push_back(sec);
        return res;
    }
};