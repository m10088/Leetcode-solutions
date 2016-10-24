```c++
#define N 107
int visit[2][2*N],cnt;  
void dfs(int col,int n){  
    if(col==n){cnt++;return;}  
    for(int i=0;i<n;i++){  
        if(visit[0][i]==0&&visit[1][i+col]==0&&visit[2][i-col+n]==0){  
            visit[0][i]=visit[1][i+col]=visit[2][i-col+n]=1;  
            dfs(col+1,n);  
            visit[0][i]=visit[1][i+col]=visit[2][i-col+n]=0;  
        }  
    }  
}  

class Solution {
public:
    int totalNQueens(int n) {
        memset(visit,0,sizeof(visit));
        cnt=0;
        dfs(0,n);
        return cnt;
    }
}
```
