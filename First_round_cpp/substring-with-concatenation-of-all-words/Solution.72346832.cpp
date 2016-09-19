


class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ret;
        if (words.size() == 0) return ret;
        int l_size = words.size();
        int word_size = words[0].size();
        int n = s.size();
        map<string,int> ori;
        for (int i=0; i<words.size(); i++) {
            ori[words[i]]++;
        }
        map<string,int> counter;
        for (int i=0; i<=(n-l_size*word_size); i++) {
            counter.clear();
            int j;
            for (j=0; j<l_size; j+=1) {
                string tmp = s.substr(i + j * word_size, word_size);
                
                counter[tmp]++;
                if (ori[tmp] < counter[tmp]) {
                   // cout << "now " << i << " " << j << endl;
                    break;
                }
            }
            if (j == l_size) {
                ret.push_back(i);
            }
        }
        return ret;
    }
};