```c++
#define N 107
int visit[3][2*N];
char d[N][N];
void PushToRes(vector<vector<string>>&res,int n){
    vector<string> tmp;
    for(int i=0;i<n;i++){
        string line;
        for(int j=0;j<n;j++){
            line.push_back(d[i][j]);
        }
        tmp.push_back(line);
    }
    res.push_back(tmp);
}
void dfs(int col,int n,vector<vector<string>>&res){  
    if(col==n){PushToRes(res,n);return;}  
    for(int i=0;i<n;i++){  
        if(visit[0][i]==0&&visit[1][i+col]==0&&visit[2][i-col+n]==0){  
            visit[0][i]=visit[1][i+col]=visit[2][i-col+n]=1;
            d[i][col]='Q';
            dfs(col+1,n,res);  
            visit[0][i]=visit[1][i+col]=visit[2][i-col+n]=0;
            d[i][col]='.';
        }  
    }  
}  

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        memset(visit,0,sizeof(visit));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                d[i][j]='.';
            }
        }
        vector<vector<string>> res;
        dfs(0,n,res);
        return res;
    }
}
```
