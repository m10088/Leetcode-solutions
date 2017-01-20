template<typename T>
std::string ToString(T x){
    std::stringstream sout;
    sout << x;
    return sout.str();
}


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
        
       for(auto p=s.begin();p!=s.end();){
           if((*p)==' '){
               p=s.erase(p);
           }else{
               p++;
           }
       }
       
        vector<string> v;
        auto p=s.begin();
        auto q=p+1;
        while(p!=s.end()){
            if((*p)<='9'&&(*p)>='0'){
                while(q!=s.end()&&(*q)<='9'&&(*q)>='0'){
                    q++;
                }
                v.push_back(string(p,q));
                p=q;
                q=p+1;
            }else{
                
                v.push_back(string(p,q));
                p=q;
                q=q+1;
            }
            
        }
        
        vector<string> rev;
        vector<string> stack;
        for(int i=0;i<v.size();i++){
            if(v[i][0]<='9'&&v[i][0]>='0'){
                rev.push_back(v[i]);
            }else if(v[i]=="("){
                stack.push_back("(");
            }else if(v[i]==")"){
                while(stack.back()!="("){
                    rev.push_back(stack.back());
                    stack.pop_back();
                }
                stack.pop_back();
            }else{
                while(stack.empty()==false&&stack.back()!="("){
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
                }else{
                    cout<<"error"<<endl;
                }
            }
        }
        return res[0];
    }
};