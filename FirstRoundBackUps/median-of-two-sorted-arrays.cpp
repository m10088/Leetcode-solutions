class Solution {
public:
double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size() + nums2.size();
        if (n==0) return 0;
        vector<int> v(n, 0);
        int p=0,q=0,k=0;
        while (k < n) {
            if (q==nums2.size()) {
                v[k++] = nums1[p++];
            } else if (p==nums1.size()) {
                v[k++] = nums2[q++];
            } else if (nums1[p] <= nums2[q]){
                v[k++] = nums1[p++];
            } else {
                v[k++] = nums2[q++];
            }
        }
        //for (int i=0; i<n; i++) cout << v[i] << " "; cout << endl;
        if (n % 2 == 1) {
            return v[n/2];
        } else {
            return (v[(n-1)/2] + v[n/2]) * 1.0/2;
        }
    }
};