class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        
        int n=matrix.size();
        int m=matrix[0].size();
        bool *row_flag= new bool[n],*col_flag= new bool[m];
        for(int i=0;i<n;i++){row_flag[i]=false;}
        for(int i=0;i<m;i++){col_flag[i]=false;}
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!matrix[i][j]){
                    row_flag[i]=true;
                    col_flag[j]=true;
                }
            }
        }
        
        for(int i=0;i<n;i++){
            if(row_flag[i]){
                for(int j=0;j<m;j++){
                    matrix[i][j]=0;
                }
            }
        }
        
        for(int j=0;j<m;j++){
            if(col_flag[j]){
                for(int i=0;i<n;i++){
                    matrix[i][j]=0;
                }
            }
        }
        
    }
};