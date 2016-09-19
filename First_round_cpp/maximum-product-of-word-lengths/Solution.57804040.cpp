int Compress(const string&s){
    int res=0;
    for(int i=0;i<s.size();i++){
        res=res|(1<<(s[i]-'a'));
    }
    return res;
}
class Solution {
public:
    int maxProduct(vector<string>& words) {
        vector<int> v;
        for(int i=0;i<words.size();i++){
            v.push_back(Compress(words[i]));
        }
 
        int maxer=0;
        for(int i=0;i<v.size();i++){
            for(int j=i+1;j<v.size();j++){
                if((v[i]|v[j])==v[i]+v[j]){
                    int tar=words[i].size()*words[j].size();
                    maxer=std::max(maxer,tar);
                }
            }
        }
        return maxer;
    }
};