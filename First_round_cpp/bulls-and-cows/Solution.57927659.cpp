template<typename T>
//intè½¬åæstring
std::string ToString(T x){
    std::stringstream sout;
    sout << x;
    return sout.str();
}

class Solution {
public:
    string getHint(string s, string g) {
        if(s.size()==0)return "0A0B";
        int fir=0,sec=0;
        for(int i=0;i<s.size();i++){
            if(s[i]==g[i]){
                s[i]=g[i]='.';
                fir++;
            }
        }
        for(int i=0;i<s.size();i++){
            if(s[i]=='.')continue;
            for(int j=0;j<s.size();j++){
                    if(s[i]==g[j]){
                        s[i]=g[j]='.';
                        sec++;
                        break;
                    }
                }
        }
        
        string res;
        res+=ToString<int>(fir);
        res.push_back('A');
        res+=ToString<int>(sec);
        res.push_back('B');
        return res;
    }
};