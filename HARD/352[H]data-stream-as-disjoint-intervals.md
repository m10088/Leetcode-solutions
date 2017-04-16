[原题](https://leetcode.com/problems/data-stream-as-disjoint-intervals)

题意

题解

```
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
    void addNum(int val) {
        auto it = st.lower_bound(Interval(val, val)); // 返回第一个满足>=的指针，类似数组的lower_bound
        int start = val, end = val;
        if (it != st.begin() && (--it)->end+1 < val) it++;
        int counter = 0;
        while (it != st.end() && val >= it->start-1 && val <= it->end+1) { // 这个循环最多进行两次
            start = min(start, it->start);
            end = max(end, it->end);
            it = st.erase(it);
            counter ++;
            assert(counter<=2);
        }
        st.insert(it,Interval(start, end));
    }
    
    vector<Interval> getIntervals() {
        vector<Interval> result;
        for(auto val: st) result.push_back(val);
        return result;
    }
private:
    struct Cmp{
        bool operator()(Interval a, Interval b){ return a.start < b.start; }
    };
    set<Interval, Cmp> st;
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges obj = new SummaryRanges();
 * obj.addNum(val);
 * vector<Interval> param_2 = obj.getIntervals();
 */
```