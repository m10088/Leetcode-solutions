template<typename T>
T StringTo(const std::string &s){
    std::stringstream sout;
    sout << s;
    T tmp;
    sout >> tmp;
    return tmp;
}
bool Noalpha(const string&s){
    for(int i=0;i<s.size();i++){
        if(!(s[i]<='9'&&s[i]>='0'))
        return false;
    }
    return true;
}

class Solution {
public:
    vector<int> diffWaysToCompute(string s) {
        vector<int> res;
        if(Noalpha(s)){
            res.push_back(StringTo<int>(s));
            return res;
        }
        vector<int>l,r;
        for(int i=0;i<s.size();i+=1){
            if(s[i]<='9'&&s[i]>='0')continue;
            
            l=diffWaysToCompute(string(s.begin(),s.begin()+i));
            r=diffWaysToCompute(string(s.begin()+i+1,s.end()));
            
            switch(s[i]){
                case '+':{
                    for(int i=0;i<l.size();i++){
                        for(int j=0;j<r.size();j++){
                            res.push_back(l[i]+r[j]);
                        }
                    }
                }break;
                case '-':{
                    for(int i=0;i<l.size();i++){
                        for(int j=0;j<r.size();j++){
                            res.push_back(l[i]-r[j]);
                        }
                    }
                }break;
                case '*':{
                    for(int i=0;i<l.size();i++){
                        for(int j=0;j<r.size();j++){
                            res.push_back(l[i]*r[j]);
                        }
                    }
                }break;
                default:
                    ;
            }
        }
        sort(res.begin(),res.end());
        
        return res;
    }
};