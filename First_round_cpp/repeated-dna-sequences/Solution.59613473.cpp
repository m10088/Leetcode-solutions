unordered_map<char,int> m;

unordered_map<int,int>times;
unordered_map<int,int>beg;//ä¿å­ç¼ç åå¼å§çä½ç½®çé®å¼å¯¹

int decode(int begin,const string&s){
    int ans=0;
    for(int i=begin;i<begin+10;i++){
        ans=ans+m[s[i]];
        ans=ans<<2;
    }
    return ans;
}

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        
        vector<string> res;
        if(s.size()<10)return res;
        m.clear();
        times.clear();
        beg.clear();
        m['A']=0;
        m['C']=1;
        m['G']=2;
        m['T']=3;
        for(int i=0;i<=s.size()-10;i++){
            
            int code=decode(i,s);
            beg[code]=i;
            times[code]++;
        }
        for(auto p=times.begin();p!=times.end();p++){
            if(p->second > 1){
                int pos=beg[p->first];
                res.push_back(string(s.begin()+pos,s.begin()+pos+10));
            }
        }
        return res;
        
    }
};