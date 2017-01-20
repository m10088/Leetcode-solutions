class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        
        vector<vector<int>> res(n);
        for(auto & x:res){
            x.resize(n);
        }
        if(n==0)return res;
        int cnt=1,x=0,y=0;
        
        while(1){
            
            do{
                res[x][y++]=cnt++;
            }while(y<n&&res[x][y]==0);
            y--,cnt--;
            
            do{
                res[x++][y]=cnt++;
            }while(x<n&&res[x][y]==0);
            x--,cnt--;
            
            
            do{
                res[x][y--]=cnt++;
            }while(y>=0&&res[x][y]==0);
            y++,cnt--;
            
            do{
                res[x--][y]=cnt++;
            }while(x>=0&&res[x][y]==0);
            x++,cnt--;
            if(cnt==n*n)break;
        }
        return res;
    }
};