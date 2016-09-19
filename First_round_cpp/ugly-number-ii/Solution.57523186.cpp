class Solution {
public:
    //çæä¸æ°çæçé®é¢ï¼å°å·²ç»æ¾å°çåºåä¸­çä¸æ°åå«*2ï¼*3ï¼*5ï¼
    //å³äºèµ·ç¹ï¼åç»ç¹ï¼å¯ä»¥æ¯è¾é«æçç¡®è®¤ï¼ç¶åæ¯è¾ï¼éåºé£ä¸ªæå¤§çåç´ å°±æ¯äºï¼
    int nthUglyNumber(int n) {
        vector<int> res{0,1,2,3,4,5};
        if(n<=5)return res[n];
        for(int i=6;i<=n;i++){
            vector<int>::iterator a,b,c;
            auto two_begin=lower_bound(res.begin(),res.end(),res[res.size()-1]/2-1);
            auto three_begin=lower_bound(res.begin(),res.end(),res[res.size()-1]/3-1);
            auto five_begin=lower_bound(res.begin(),res.end(),res[res.size()-1]/5-1);
           
            for(a=two_begin;(*a)*2<=res[res.size()-1];a++){}
            for(b=three_begin;(*b)*3<=res[res.size()-1];b++){}
            for(c=five_begin;(*c)*5<=res[res.size()-1];c++){}
            res.push_back(std::min(*a*2,(std::min(*b*3,*c*5))));
        }
        return res[n];
    }
};