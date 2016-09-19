class Solution {
public:
    int findPeakElement(vector<int>& a) {
        int n=a.size();
        if(a.size()==1)return 0;
        if(n==2){
            if(a[0]>a[1])return 0;
            else return 1;
        }
        int lo=0,hi=n-1;
        while(1){
            if(lo+1==hi){
                if(a[lo]>a[hi])return lo;
                else return hi;
            }
            auto mid=lo+(hi-lo)/2;
            if(mid==0||mid==n-1){
                return mid;
            }else{
                if(a[mid]>a[mid-1]&&a[mid]>a[mid+1]){
                    return mid;
                }else if(a[mid+1]>a[mid-1]){
                    lo=mid;
                }else{
                    hi=mid;
                }
            }
        }
        return lo;
    }
};