```c++
/**
* Definition for an interval.
* struct Interval {
    * int start;
    * int end;
    * Interval() : start(0), end(0) {}
    * Interval(int s, int e) : start(s), end(e) {}
    * };
*/
class SummaryRanges {
    public:
        /** Initialize your data structure here. */
        SummaryRanges() {
            
            st.clear();
        }

        void addNum(int val) {
            
            

            
            

            st.insert(val);

        }

        vector<Interval> getIntervals() {
            
            vector<Interval> ret;
            int begin, end;
            int last = -2;
            for (auto p = st.begin(); p != st.end(); p++) {
                if (*(p) != last + 1) {
                    if (p != st.begin())
                        ret.push_back(Interval(begin, end));
                    begin = end = *p;
                    } else {
                    end = *p;
                }
                last = *p;
            }
            ret.push_back(Interval(begin, end));
            return ret;
        }
        
        set<int> st;
};
```
