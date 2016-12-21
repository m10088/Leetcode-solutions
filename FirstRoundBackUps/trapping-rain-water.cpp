//ç»´æ¤ä¸ä¸ªå½åçå·¦å³åºé´ç«¯ç¹å·²ç»éåè¿çæå¤§å¼åç¬¬äºå¤§çå¼
class Solution {
public:
    int trap(vector<int>& a) {
            if(a.size()==0)return 0;
            int lo=0;
            int hi=a.size()-1;
            int ans=0;
            int fir=std::max(a[lo],a[hi]);
            int sec=std::min(a[lo],a[hi]);
            int wheresec;
            if(sec==a[lo])
                wheresec=0;
            else
                wheresec=1;
            int flag=wheresec;//æéæ¨è¿æ å¿
            while(lo<hi){
                if(flag==0){
                    lo++;
                    if(a[lo]<=sec){//æ¯æå°çè¿å°
                        ans+=(sec-a[lo]);
                        cout<<"adder"<<sec-a[lo]<<"_in_"<<lo<<endl;
                    }else if(a[lo]>sec&&a[lo]<fir){//å¤äºä¸¤èä¹é´èä¸ç¬¬äºå¤§çä½ç½®å¨æä»¬è¿è¾¹ææ´æ°
                        if(wheresec==0)
                            sec=a[lo];
                    }else{//ç´æ¥è¶è¿äºæå¤§çå¼
                        sec=fir;
                            wheresec=1;
                        fir=a[lo];
                        flag=1;//äº¤æ¢æé
                    }
                }else{
                    hi--;
                    if(a[hi]<=sec){
                        ans+=(sec-a[hi]);
                        cout<<"adder"<<sec-a[hi]<<"_in_"<<hi<<endl;
                    }else if(a[hi]>sec&&a[hi]<fir){
                        if(wheresec==1)
                            sec=a[hi];
                    }else{
                        sec=fir;
                            wheresec=0;
                        fir=a[hi];
                        flag=0;
                    }
                }
                
            }
            return ans;
    }
};