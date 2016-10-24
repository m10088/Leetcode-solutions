```c++
unordered_map<int,int> m;
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        m.clear();
        for(int i=0;i<nums.size();i++){
            m[nums[i]]++;
        }
        for(auto p=m.begin();p!=m.end();p++){
            if(p->second!=3)return p->first;
        }
        return 1;
    }
}
```
