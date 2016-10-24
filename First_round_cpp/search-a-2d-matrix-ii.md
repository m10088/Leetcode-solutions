```c++
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.size()==0)return false;
        int n=matrix.size()-1,m=matrix[0].size()-1;
        
        int i=0,j=m;
        while(i<=n&&j>=0){
            if(matrix[i][j]==target)
                return true;
            else if(matrix[i][j]<target){
                i++;
            }else{
                j--;
            }
        }
        return false;
    }
}
```
