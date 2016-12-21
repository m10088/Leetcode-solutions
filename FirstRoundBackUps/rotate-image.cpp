class Solution {
public:
    void rotate(vector<vector<int>>& v) {
        int M;
        if(v.size()%2)
        M=v.size()/2+1;
        else
        M=v.size()/2;
        int s=v.size()-1;
        
        if(v.size()%2==0)
        {
            for(int y=0;y<M;y++)
            {
                for(int x=0;x<M;x++)
                {
                  
                    int tmp=v[s-x][y];
                    v[s-x][y]=v[s-y][s-x];
                    v[s-y][s-x]=v[x][s-y];
                    v[x][s-y]=v[y][x];
                    v[y][x]=tmp;
                }
            }
        }
        else
        {
            
            for(int y=0;y<M-1;y++)
            {
                for(int x=0;x<M;x++)
                {
                  
                    int tmp=v[s-x][y];
                    v[s-x][y]=v[s-y][s-x];
                    v[s-y][s-x]=v[x][s-y];
                    v[x][s-y]=v[y][x];
                    v[y][x]=tmp;
                }
            }
            
        }
    }
};