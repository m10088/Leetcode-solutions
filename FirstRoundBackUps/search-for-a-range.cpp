class Solution {
public:
    vector<int> searchRange(vector<int>& num, int target) {
        vector<int>res;
        auto begin=lower_bound(num.begin(),num.end(),target);
        auto end=upper_bound(num.begin(),num.end(),target);
        if(begin==end){
            res.push_back(-1);
            res.push_back(-1);
            return res;
        }else{
            res.push_back(begin-num.begin());
            res.push_back(end-num.begin()-1);
            return res;
        }
        
    }
};