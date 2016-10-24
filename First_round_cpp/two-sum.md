```c++
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
        map<int,int> info;
        for(auto i=0;i<nums.size();i++){
            auto p=info.find(target-nums[i]);
                if(p==info.end()){
                    info[nums[i]]=i;
                }else{
                    res.push_back(p->second);
                    res.push_back(i);
                    break;
                }
        }    
        return res;
    }
}
```
