/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class SummaryRanges {
public:
    /** Initialize your data structure here. */
    SummaryRanges() {
        //fa.clear();
        st.clear();
    }
    
    void addNum(int val) {
        // if (fa.find(val-1)==fa.end()) fa[val] = val; //å¦ææ¾ä¸å°ä¸ä¸ä¸ªåç´ ï¼å°±å°è¿ä¸ªåç´ èªå·±æ¾å°éåä¸­
        // else fa[val] = val-1;
        
        // if (fa.find(val+1) == fa.end()) {} //å¦ææ¾ä¸å°ä¸ä¸ä¸ªåç´ ï¼ç´æ¥è·³è¿
        // else fa[val+1] = val;
        
        st.insert(val);
        
    }
    
    vector<Interval> getIntervals() {
        // auto p = fa.end();
        vector<Interval> ret;
        int begin, end;
        int last = -2;
        for (auto p=st.begin(); p!=st.end(); p++) {
            if (*(p) != last+1) {
                if (p!=st.begin())
                    ret.push_back(Interval(begin,end));
                begin = end = *p;
            } else {
                end = *p;
            }
            last = *p;
        }
        ret.push_back(Interval(begin, end));
        return ret;
    }
    //map<int,int> fa;
    set<int> st;
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges obj = new SummaryRanges();
 * obj.addNum(val);
 * vector<Interval> param_2 = obj.getIntervals();
 */