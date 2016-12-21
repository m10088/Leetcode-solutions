class Solution {
public:
    vector<int> twoSum(vector<int>& v, int target) {
        int n = v.size();
        vector<int> ret;
        if (n==0 || n == 1) return ret;
        int j = n-1, i = 0;
        while (i < j) {
            if (v[i] + v[j] == target) {
                ret.push_back(i+1);
                ret.push_back(j+1);
                return ret;
            } else if (v[i] + v[j] < target) {
                i ++;
            } else {
                j --;
            }
        }
        return ret;
    }
};