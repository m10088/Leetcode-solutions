#define INF 0x7fffffff
int n, m;
int cnt(vector<vector<int>> v, int tar) {
    
    int y=m-1, x=0;
    int ret = 0;
    while (x != n) {
        if (v[x][y] < tar) {
            ret += (y+1);
            x++;
        } else {
            y--; 
            if (y==-1)
                return ret;
        }
    }
    return ret;
}
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        if (matrix.size()==0) return 0;
        else n = matrix.size(), m = matrix[0].size();
        long long left = -INF, right = INF;
        long long mid;
        while (right - left > 1) {
            mid = (left + right) >> 1;
            int tmp = cnt(matrix, mid);
            if (tmp <= k-1) left = mid;
            else right = mid;
        }
        return left;
    }
};