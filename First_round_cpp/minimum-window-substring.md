```c++
struct Node {
    int ss, m;
    Node(){ss = m = 0;}
};
bool is_notcomplete(unordered_map<char, Node>&m) {
    for (auto p = m.begin(); p != m.end(); p++) {
        auto node = p->second;
        if (node.ss > node.m)return true;
    }
    return false;
}

class Solution {
    public:
        string minWindow(string a, string sub) {
            unordered_map<char, Node> m;
            for (int i = 0; i < sub.size(); i++) {
                m[sub[i]].ss++;
            }

            int begin = 0, end = 0;
            int s = 0, t = 0;
            int n = a.size(), miner = n + 1;

            while (1) {

                while (t < n && is_notcomplete(m)) {

                    m[a[t++]].m++;

                }
                if (is_notcomplete(m)) {
                    break;
                }

                if (t - s < miner) {
                    miner = t - s;
                    begin = s,end = t;
                }

                m[a[s]].m--;
                s++;

            }
            return string(a.begin() + begin, a.begin() + end);
        }
}
```
