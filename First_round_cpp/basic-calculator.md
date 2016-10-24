```c++
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
```
