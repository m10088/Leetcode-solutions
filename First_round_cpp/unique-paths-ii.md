```c++
int d[101][101];
int f(vector<vector<int>> & v,int i,int j,int m,int n)
{
    if(d[i][j]!=-1)return d[i][j];
    if(v[i-1][j-1]==1)
        return d[i][j]=0;
    if(i==m&&j==n)return d[i][j]=1;
    if(i==m&&j<n)return d[i][j]=f(v,i,j+1,m,n);
        if(j==n&&i<m)return d[i][j]=f(v,i+1,j,m,n);
        if(i<m&&j<n)return d[i][j]=f(v,i+1,j,m,n)+f(v,i,j+1,m,n);
}
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& v) {
        int m=v.size();
        if(m==0) return 0;
        int n=v[0].size();
        for(auto i=0;i<101;i++)
        {
            for(auto j=0;j<101;j++)
            d[i][j]=-1;
        }
        return f(v,1,1,m,n);
        
    }
}
```
