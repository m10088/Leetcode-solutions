int target;
vector<string> res;

class Solution {
public:
    vector<string> addOperators(string num, int tar) {
        res.clear();
        target = tar;
        addOperatorsDFS(num, 0, 0, "");
        return res;
    }
    void addOperatorsDFS(string num, long long diff, long long curNum, string out) {
        if (num.size() == 0 && curNum == target) {
            res.push_back(out);
        }
        for (int i = 1; i <= num.size(); ++i) {
            string cur = num.substr(0, i);
            if (cur.size() > 1 && cur[0] == '0') return;
            string next = num.substr(i);
            if (out.size() > 0) {
                addOperatorsDFS(next, stoll(cur), curNum + stoll(cur), out + "+" + cur);
                addOperatorsDFS(next, -stoll(cur), curNum - stoll(cur), out + "-" + cur);
                addOperatorsDFS(next, diff * stoll(cur), (curNum - diff) + diff * stoll(cur), out + "*" + cur);
            } else {
                addOperatorsDFS(next, stoll(cur), stoll(cur), cur);
            }
        }
    }
};