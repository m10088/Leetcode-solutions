```c++
struct Node {
    int fir,sec;
    Node(int fir_,int sec_):fir(fir_), sec(sec_) {}
    Node() {}
    bool operator <(const Node& n) const { return fir+sec > n.fir + n.sec; }
};
priority_queue<Node> pq;

class Solution {
public:
    vector<pair<int, int> > kSmallestPairs(vector<int>& v1, vector<int>& v2, int k) {
        while (pq.size()!=0) pq.pop();
        vector<pair<int,int> > ret;
        if (v1.size()==0 || v2.size()==0 ) return ret;
        int n1 = v1.size(), n2 = v2.size();
        
        for (int i=0; i<n1; i++) { pq.push(Node(v1[i], v2[0])); }
        int now = 1;
        while (k--) {
            if (pq.size()==0) break;
            Node fro = pq.top();
            pq.pop();
            ret.push_back(pair<int,int>(fro.fir, fro.sec));
            if (now < v2.size()) {
                for (int i=0; i<v1.size(); i++) { pq.push(Node(v1[i], v2[now])); }
                now ++;
            }
        }
        return ret;
    }
}
```
