class Solution {  
public:  
    int minPatches(vector<int>& nums, int n) {  
       long long cur = 0;  
       int i = 0,add = 0;  
       while(cur<n){  
       if(i < nums.size()&&nums[i] <= cur + 1) {  
        cur +=nums[i];  
        i ++ ;  
       }  
    else {  
        add++;  
        cur = 2*cur + 1;  
      }  
    }  
    return add;    
    }  
};  