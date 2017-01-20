class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& v) {
        if(v.size()==0)return 0;
        int n=v.size(),m=v[0].size();
        vector<vector<int>> a(n);
        for(int i=0;i<n;i++){
            a[i].resize(m);
        }
        

        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                if(j==m-1&&i==n-1){
                    a[i][j]=1;
                }else if(i==n-1&&j!=m-1){
                    int tmp=a[i][j+1]-v[i][j+1];
                    if(tmp<=0){
                        a[i][j]=1;
                    }else{
                        a[i][j]=tmp;
                    }
                }else if(i!=n-1&&j==m-1){
                    int tmp=a[i+1][j]-v[i+1][j];
                    if(tmp<=0){
                        a[i][j]=1;
                    }else{
                        a[i][j]=tmp;
                    }
                }else{
                    int tmp=std::min(a[i][j+1]-v[i][j+1],a[i+1][j]-v[i+1][j]);
                    
                    if(tmp<=0){
                        a[i][j]=1;
                    }else{
                        a[i][j]=tmp;
                    }
                }
            }
        }
       
        int tmp=a[0][0]-v[0][0];
        if(tmp<=0)return 1;
        else return tmp;
        
       
    }
};