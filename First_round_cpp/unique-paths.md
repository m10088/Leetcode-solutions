```c++
int d[101][101];

int  f(int i,int j,int M,int N)
{
    if(d[i][j]!=-1)return d[i][j];
    if(i==M&&j==N)return d[i][j]=1;
    else
    {
        if(i==M&&j<N)return d[i][j]=f(i,j+1,M,N);
        if(j==N&&i<M)return d[i][j]=f(i+1,j,M,N);
        if(i<M&&j<N)return d[i][j]=f(i+1,j,M,N)+f(i,j+1,M,N);
        else 
        {
            std::cout<<"unkonw error"<<std::endl;
        }
    }
    
}
class Solution {
public:
    int uniquePaths(int m, int n)
    {
        for(auto i=0;i<101;i++)
        {
            for(auto j=0;j<101;j++)
            {
                d[i][j]=-1;
            }
        }
        
        
        return f(1,1,m,n);
    }
}
```
