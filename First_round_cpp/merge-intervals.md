```c++
/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
 bool cmp(const Interval&n1,const Interval&n2){
     return n1.end < n2.end;
 }
class Solution {
public:
    vector<Interval> merge(vector<Interval>& v) {
        sort(v.begin(),v.end(),cmp);
        vector<Interval> res;
        int e,b,cur;
        if(v.size()<2)return v;
        int n=v.size();
        cur=n-1;
        e=v[cur].end;
        b=v[cur].start;
        cur--;
        int cnt=0;
        while(1){
        
           
            if(v[cur].end<b){
                res.push_back(Interval(b,e));
                b=v[cur].start;
                e=v[cur].end;
                cur--;
            }else if(v[cur].end>=b&&v[cur].start<b){
                b=v[cur].start;
                cur--;
            }else{
                cur--;
            }
            if(cur<0){
                res.push_back(Interval(b,e));
                break;
            }
        }
        
        reverse(res.begin(),res.end());
        return res;
    }
}
```
