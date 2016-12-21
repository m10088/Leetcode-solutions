#define N 2007
#define INF 0x7fffffff
int is[N][N];
int dfs_is(int i,int j,const string& s){
    if(is[i][j]!=-1) return is[i][j];
    if(i==j) return is[i][j]=1;
    if(i+1==j){
        if(s[i]==s[j]) return is[i][j]=1;
        else return is[i][j]=0;
    }
    if(s[i]!=s[j]) return is[i][j]=0;
    if(s[i]==s[j]) return is[i][j]=dfs_is(i+1,j-1,s); 
    return 0;
}

class Solution {
public:
    int minCut(string s) {
        cout<<s.size()<<endl;
        memset(is,-1,sizeof(is));
        dfs_is(0,s.size()-1,s);
        int* cur=new int[s.size()];
        memset(cur,0,sizeof(cur));
        cur[0]=0;
        for(int i=1;i<s.size();i++){
            cur[i]=i;
            for(int j=0;j<=i;j++){
                if(j==0&&dfs_is(0,i,s)){
                    cur[i]=0;
                }
                if(dfs_is(j,i,s)){
                    cur[i]=std::min(cur[i],cur[j-1]+1);
                }
            }
        }
        return cur[s.size()-1];
    }
};