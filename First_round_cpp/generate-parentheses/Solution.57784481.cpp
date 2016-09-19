//åæº¯ï¼æ¾ç½®çåæ¬å·çæ°éä¸è½è¶è¿å·¦æ¬å·çæ°é
void dfs(vector<string>&final,string&tmp,int lc,int rc,int n,int depth){
    if(rc==n+1||lc==n+1)
        return;
    if(depth==n*2){
        final.push_back(string(tmp.begin(),tmp.begin()+depth));
    }
    
    if(rc+1>lc){//ä¸è½æ¾å³æ¬å·
        tmp[depth]='(';
        dfs(final,tmp,lc+1,rc,n,depth+1);
    }else{//æ¢å¯ä»¥æ¾å·¦æ¬å·ï¼ä¹å¯ä»¥æ¾å³æ¬å·
        tmp[depth]='(';
        dfs(final,tmp,lc+1,rc,n,depth+1);
        tmp[depth]=')';
        dfs(final,tmp,lc,rc+1,n,depth+1);
    }
    
}
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        string tmp;
        vector<string>res;
        tmp.resize(307);
        dfs(res,tmp,0,0,n,0);//å·¦è¾¹å·²ç»æå¤å°ä¸ªï¼å³è¾¹å·²ç»æå¤å°ä¸ªï¼éå¶æ¯å¤å°ä¸ªï¼ç°å¨æ·±åº¦æ¯ä»ä¹
        return res;
    }
};