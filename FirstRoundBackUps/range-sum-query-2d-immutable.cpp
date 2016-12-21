#define N 1007
class NumMatrix {
public:
    int sum[N][N];
    //è¿ä¸ªé¢ç®æç¹å...
    NumMatrix(vector<vector<int>> &v) {
        if(v.size()==0)return;
        memset(sum,0,sizeof(sum));
        int n=v.size(),m=v[0].size();
        //åæç¬¬ä¸è¡åç¬¬ä¸åæ´æ°å®
        sum[0][0]=v[0][0];
        for(int i=1;i<m;i++)sum[0][i]=sum[0][i-1]+v[0][i];
        for(int i=1;i<n;i++)sum[i][0]=sum[i-1][0]+v[i][0];
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                sum[i][j]=sum[i-1][j]+sum[i][j-1]+v[i][j]-sum[i-1][j-1];
            }
        }
    }
    int get(int row,int col){
        if(row==-1||col==-1)return 0;
        else return sum[row][col];
    }
    int sumRegion(int row1, int col1, int row2, int col2) {
        return get(row2,col2)+get(row1-1,col1-1)-get(row1-1,col2)-get(row2,col1-1);
    }
};


// Your NumMatrix object will be instantiated and called as such:
// NumMatrix numMatrix(matrix);
// numMatrix.sumRegion(0, 1, 2, 3);
// numMatrix.sumRegion(1, 2, 3, 4);