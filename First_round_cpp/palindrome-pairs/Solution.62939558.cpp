#define N 1007

unordered_map<string,vector<int>> lefter1;

unordered_map<string,vector<int>> righter2;


bool isp(const string&s){
    if(s.size()==0)return true;
    int p=0,q=s.size()-1;
    while(p<q){
        if(s[p]==s[q]){
            p++,q--;
        }else{
            return false;
        }
    }
    return true;
}

int cnt;
class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& v) {//wordsåºè¯¥ä¸ä¼åçéå¤
        vector<vector<int>> res;
        lefter1.clear(),righter2.clear(),cnt=0;
        if(v.size()==0)return res;
        for(int i=0;i<v.size();i++){
            //èèç¬¬ä¸ç§æåµæ¯å¦æ»¡è¶³
            string &s =v[i];
            const string& rs=string(s.rbegin(),s.rend());
           
            //å¤çæ¬å­ç¬¦ä¸²
            //rightå¯è½æ¯åææ°
            for(auto j=s.end();j>=s.begin();j--){
                if(isp(string(j,s.end()))){
                     
                    lefter1[string(s.begin(),j)].push_back(i);
                }
            }
            
            //leftå¯è½æ¯åææ°
            for(auto j=s.begin();j<=s.end();j++){
                if(isp(string(s.begin(),j))){
                    
                    righter2[string(j,s.end())].push_back(i);
                }
            }
            
        }
        for(int i=0;i<v.size();i++){
            //èèç¬¬ä¸ç§æåµæ¯å¦æ»¡è¶³
            string &s =v[i];
            const string& rs=string(s.rbegin(),s.rend());
             if(lefter1.find(rs)!=lefter1.end()){
                for(int j=0;j<lefter1[rs].size();j++){
                   if(lefter1[rs][j]!=i)
                    res.push_back(vector<int>{lefter1[rs][j],i});
                }
            }
            //èèç¬¬äºç§æåµæ¯å¦æ»¡è¶³
            if(righter2.find(rs)!=righter2.end()){
                for(int j=0;j<righter2[rs].size();j++){
                   if(i!=righter2[rs][j])
                    res.push_back(vector<int>{i,righter2[rs][j]});
                }
            }
        }
        sort(res.begin(),res.end());
        res.erase(unique(res.begin(),res.end()),res.end());
        return res;
    }
};