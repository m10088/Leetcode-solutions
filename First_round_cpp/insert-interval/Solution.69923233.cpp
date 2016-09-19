/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
bool cmp(const Interval& v1, const Interval &v2) {
    return v1.start < v2.start;
}
class Solution {
public:
    vector<Interval> insert(vector<Interval>& a, Interval x) {
        int b = x.start, e = x.end;
        vector<Interval> ret;
        int n = a.size();
        int fir=-1, sec=-1;
        if (n==0) { ret.push_back(x); return ret; }
        
        //åå¤æ­æ¯ä¸æ¯åå«å¨å·²ç»æ¥æçåºé´å
        // int ok = false;
        // for (int i=0; i<n; i++) {
        //     if (a[i].end > e && a[i].start < b) {
        //         ok = true;
        //         break;
        //     }
        // }
        // if (ok) return a;
        
        for (int i=0; i<n; i++) {
            if (a[i].start <= b && b <= a[i].end) {
                fir = i;
            } 
            if (a[i].start <= e && e <= a[i].end) {
                sec = i;
            }
        }
        
        //è¿éåä¸ºå ç§æåµï¼
        //1.åä»»ä½åºé´æ²¡æäº¤éï¼ä½æ¯å¯è½å·²ç»åå«äºæäºåºé´
        if (fir == -1 && sec == -1) {
            for (int i=0; i<n; i++) {
                if (a[i].start > b && a[i].end < e) {}
                else ret.push_back(a[i]);
            }
            ret.push_back(x);
        }
        //2.è·¨è¿äºä¸¤ä¸ªåºé´
        else if (fir != -1 && sec != -1) {
            for (int i=0; i<n; i++) {
                if (i==fir || i==sec) {}
                else if (a[i].start > b && a[i].end < e) {}
                else ret.push_back(a[i]);
            }
            ret.push_back(Interval(a[fir].start, a[sec].end));
        }
        //3.åªæ¯è·¨è¿äºåä¸ªåºé´
        else if (fir != -1 && sec == -1) {
            for (int i=0; i<n; i++) {
                if (i==fir) {}
                else if (a[i].start > b && a[i].end < e) {}
                else ret.push_back(a[i]);
            }
            ret.push_back(Interval(a[fir].start, e));
        }
        //4.åªæ¯è·¨è¿äºåä¸ªåºé´
        else {
            for (int i=0; i<n; i++) {
                if (i==sec) {}
                else if (a[i].start > b && a[i].end < e) {}
                else ret.push_back(a[i]);
            }
            ret.push_back(Interval(b, a[sec].end));
        }
        sort(ret.begin(), ret.end(), cmp);
        return ret;
    }
};