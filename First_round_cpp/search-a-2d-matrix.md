```c++
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.size()==0) return false;
        int n=matrix.size()-1,m=matrix[0].size()-1;
        int lo=0,hi=matrix.size()-1;
        while(lo<=hi){
            vector<vector<int>>& a=matrix;
            auto mid=lo+(hi-lo)/2;
            if(a[mid][0]<=target&&a[mid][m]>=target){
                if((*lower_bound(a[mid].begin(),a[mid].end(),target))==target){
                    return true;
                }else{
                    return false;
                }
            }else if(a[mid][0]>target){
                hi=mid-1;
            }else{
                lo=mid+1;
            }
        }
        return false;
    }
}
```
