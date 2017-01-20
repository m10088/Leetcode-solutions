class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        unordered_map<int,int> mapping;
        for(int number : nums)
            mapping[number]++;
        
        
        priority_queue<pair<int,int>> pri_que; 
        for(auto it = mapping.begin(); it != mapping.end(); it++)
            pri_que.push(make_pair(it->second, it->first));
        
        while(result.size() < k){
                result.push_back(pri_que.top().second);
                pri_que.pop();
        }
        return result;
    }
private:
    vector<int> result;
};