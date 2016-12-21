
//stringè½¬åæint
template<typename T>
T StringTo(const std::string &s){
    std::stringstream sout;
    sout << s;
    T tmp;
    sout >> tmp;
    return tmp;
}

class Solution {
public:
    int calculate(string s) {
        //é¤æç©ºæ ¼
        for(auto p=s.begin();p!=s.end();){
           if((*p)==' '){
               p=s.erase(p);
           }else{
               p++;
           }
        }
        
        vector<string> v;
        string::iterator p=s.begin(),q=p+1;
        while(p!=s.end()){
            if((*p)<='9'&&(*p)>='0'){
                while(q!=s.end()&&(*q)<='9'&&(*q)>='0'){
                    q++;
                }//å¦ææ¯æ°å­ä¸ç´æ¾å°é£ä¸ªä¸æ¯æ°å­çå­ç¬¦åä¸
                v.push_back(string(p,q));
                p=q;
                q=p+1;
            }else{
                //å¦ææ¯å¶ä»çå­ç¬¦
                v.push_back(string(p,q));
                p=q;
                q=q+1;
            }
        }
        
        vector<string> rev;
        vector<string> stack;
        for(int i=0;i<v.size();i++){
            if(v[i][0]<='9'&&v[i][0]>='0'){//æ¯æ°å­
                rev.push_back(v[i]);
            }else if(v[i]=="("){
                stack.push_back("(");
            }else if(v[i]==")"){//å°å·¦æ¬å·åé¢çå¨é¨æ¿åºæ¥
                while(stack.back()!="("){
                    rev.push_back(stack.back());
                    stack.pop_back();
                }
                stack.pop_back();
            }else if(v[i]=="+"||v[i]=="-"){//å æ³æèåæ³,å°æ¬å·åé¢çè¿ç®ç¬¦å·å¨é¨æ¿åºæ¥ï¼ç¶åå°èªå·±æ¾è¿å»
                while(stack.empty()==false&&stack.back()!="("){
                    rev.push_back(stack.back());
                    stack.pop_back();
                }
                stack.push_back(v[i]);
            }else{//ä¹æ³æèé¤æ³,åå³è¾¹æ«æéå°+-æè(å°±åæ­¢ï¼ç¶åå°èªå·±æ¾è¿å»
                while(stack.empty()==false&&stack.back()!="("&&stack.back()!="+"&&stack.back()!="-"){
                    rev.push_back(stack.back());
                    stack.pop_back();
                }
                stack.push_back(v[i]);
            }
        }
        while(stack.empty()==false){
            rev.push_back(stack.back());
            stack.pop_back();
        }
        
        //æ ¹æ®éæ³¢å°æ°è®¡ç®è¡¨è¾¾å¼çå¼
        vector<int> res;
        for(int i=0;i<rev.size();i++){
            if(rev[i][0]<='9'&&rev[i][0]>='0'){
                res.push_back(StringTo<int>(rev[i]));
            }else{
                if(rev[i]=="+"){
                    auto fir=res.back();
                    res.pop_back();
                    auto sec=res.back();
                    res.pop_back();
                    res.push_back(fir+sec);
                }else if(rev[i]=="-"){
                    auto fir=res.back();
                    res.pop_back();
                    auto sec=res.back();
                    res.pop_back();
                    res.push_back(sec-fir);
                }else if(rev[i]=="*"){
                    auto fir=res.back();
                    res.pop_back();
                    auto sec=res.back();
                    res.pop_back();
                    res.push_back(sec*fir);
                }else if(rev[i]=="/"){
                    auto fir=res.back();
                    res.pop_back();
                    auto sec=res.back();
                    res.pop_back();
                    res.push_back(sec/fir);
                }else{
                    cout<<"error"<<endl;
                }
            }
        }
        return res[0];
    }
};