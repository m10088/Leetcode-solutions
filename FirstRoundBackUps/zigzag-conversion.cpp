#define M 1000
class Solution {
public:
    string convert(string s, int n) {
        if(n==1)return s;
         vector<vector<char> > v(n);
         for(int i=0;i<n;i++){
             v[i].resize(M);
         }
         int dir=1;
         int i=0,j=0;
         for(int k=0;k<s.size();k++){
            v[i][j]=s[k];
            if(k%(n-1)==0)dir=1-dir;
            
            if(dir==0){
                i++;
            }else{
                i--;j++;
            }
         }
         string res;
         for(int i=0;i<n;i++){
             for(int j=0;j<M;j++){
                 if(v[i][j]!='\0')
                 res+=v[i][j];
             }
         }
         
         return res;
         
    }
};