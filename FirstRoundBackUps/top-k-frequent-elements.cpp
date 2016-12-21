class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        //ä¸ï¼ç»è®¡å¤é¢æ¬¡
        unordered_map<int,int> mapping;
        for(int number : nums)
            mapping[number]++;
        //äºï¼æ ¹æ®é¢æ¬¡åå¥æå¤§å ä¸­    
        // pair<first, second>: first is frequency,  second is number
        priority_queue<pair<int,int>> pri_que; //æå¤§å 
        for(auto it = mapping.begin(); it != mapping.end(); it++)
            pri_que.push(make_pair(it->second, it->first));
        //ä¸ï¼è·åç»æ    
        while(result.size() < k){
                result.push_back(pri_que.top().second);
                pri_que.pop();
        }
        return result;
    }
private:
    vector<int> result;
};