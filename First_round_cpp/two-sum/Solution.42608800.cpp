class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
      vector<int> res;
   unordered_map<int,int> info;
   for(auto i=0;i<nums.size();i++)
   {
       auto p=info.find(target-nums[i]);
       if(p==info.end())
       {
           info[nums[i]]=i;
       }
       else
       {
           res.push_back(p->second+1);
           res.push_back(i+1);
           break;
       }
   }
   return res;
    }
};