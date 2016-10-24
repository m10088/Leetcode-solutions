```c++
int GetNum(vector<vector<int>>& v,int x,int y){
    int n=v.size()-1,m=v[0].size()-1,cnt=0;
    for(int dx=-1;dx<=1;dx++){
        for(int dy=-1;dy<=1;dy++){
            if(!(dx==0&&dy==0)&&(dx+x>=0&&dx+x<=n&&dy+y>=0&&dy+y<=m)){
                if(v[x+dx][y+dy]==1||v[x+dx][y+dy]==2){
                    cnt++;
                }
            }
        }
    }
    return cnt;
}
class Solution {
public:
    void gameOfLife(vector<vector<int>>& v) {
        if(v.size()==0)return;
        int n=v.size()-1,m=v[0].size()-1,cnt;
        for(int i=0;i<=n;i++){
            for(int j=0;j<=m;j++){
                cnt=GetNum(v,i,j);
                
                
                
                
                
                
                if(v[i][j]&&(cnt<2||cnt>3))v[i][j]=2;
                else if(v[i][j]==0&&cnt==3)v[i][j]=3;
            }
        }
        for(int i=0;i<=n;i++){
            for(int j=0;j<=m;j++){
                v[i][j]=v[i][j]%2;
            }
        }
    }
}
```
