```c++
bool invector(int e,vector<int>&nums){
    for(int i=0;i<nums.size();i++){
        if(nums[i]==e)return true;
    }
    return false;
}
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        for(int i=0;i<nums1.size();i++){
            if(invector(nums1[i],nums2)){
                res.push_back(nums1[i]);
            }
        }
        sort(res.begin(),res.end());
        res.erase(unique(res.begin(),res.end()),res.end());
        return res;
    }
}
```
