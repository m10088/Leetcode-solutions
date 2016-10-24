```c++
bool Pre(const string&s){
    for(int i=0;i<s.size()/2;i++){
        if(s[i]!=s[s.size()-1-i])return false;
    }
    return true;
}

void dfs(vector<vector<string>>&final,vector<string>&tmp,const string&s,int b,int e){


    string t=string(s.begin()+b,s.begin()+e);

    if(Pre(t)){
        tmp.push_back(t);

        if(e==s.size()){

            final.push_back(tmp);
            tmp.pop_back();
            return;
        }else{
            for(int i=e+1;i<=s.size();i++){
                dfs(final,tmp,s,e,i);
            }
            tmp.pop_back();
            return;
        }
    }else{
        return;
    }
}


class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> final;
        vector<string> tmp;
        for(int i=1;i<=s.size();i++){
            dfs(final,tmp,s,0,i);
        }
        return final;
    }
}
```
