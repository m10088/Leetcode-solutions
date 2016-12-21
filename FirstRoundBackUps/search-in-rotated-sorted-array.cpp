class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(nums.size()==0)return -1;
        int min_index=-1;
        if(nums[0]<nums[nums.size()-1]){
            min_index=0;
        }else{
            int left=0,right=nums.size()-1;
            while(left<right){
                auto mid=left+(right-left)/2;
                if(nums[mid]>=nums[0]){
                    left=mid+1;
                }else{
                    right=mid;
                }
            }
            min_index=left;
        }
        int miner=nums[min_index];
        
        if(miner<=target&&target<=nums[nums.size()-1]){//å³è¾¹å¯»æ¾
            auto low=lower_bound(nums.begin()+min_index,nums.end(),target);
            auto upp=upper_bound(nums.begin()+min_index,nums.end(),target);
            if(upp==low)return -1;
            else return low-nums.begin();
        }else{
            auto low=lower_bound(nums.begin(),nums.begin()+min_index,target);
            auto upp=upper_bound(nums.begin(),nums.begin()+min_index,target);
            if(upp==low)return -1;
            else return low-nums.begin();
        }
       
        
        
    }
};