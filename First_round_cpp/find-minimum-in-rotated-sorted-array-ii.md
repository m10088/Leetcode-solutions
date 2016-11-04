```c++

int dfs(vector<int>&a, int lo, int hi) {
    if (a[lo] < a[hi])return lo;
    if (lo == hi)return lo;
    int mid = lo + (hi - lo) / 2;

    if (a[mid] < a[lo]) {
        return dfs(a, lo, mid);
        }else if(a[mid]>a[lo]){
        return dfs(a, mid + 1, hi);
        }else{
        
        if (a[mid] > a[hi])return dfs(a,mid + 1,hi);
        
        else {
            int fir = dfs(a, lo, mid);
            int sec = dfs(a, mid + 1, hi);
            if (a[fir] < a[sec])return fir;
            else return sec;
        }
    }
}

class Solution {
    public:
        int findMin(vector<int>& nums) {
            
            return nums[dfs(nums, 0, nums.size() - 1)];
        }
}
```
