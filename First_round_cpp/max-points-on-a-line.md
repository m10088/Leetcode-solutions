```c++
/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
#define INF 0x3f3f3f3f
#include <bits/stdc++.h>
using namespace std;
#define N 1007

#define EPS 1e-10
bool dequal(double x, double y) { return (fabs(x-y) < EPS); }
bool equaler(const Point & p1, const Point & p2) { return p1.x == p2.x && p1.y == p2.y; }


bool cmp(const Point &p1, const Point& p2) {
    if (p1.x == p2.x) return p1.y < p2.y;
    else return p1.x < p2.x;
}

bool equal(const Point & p1, const Point & p2) { return p1.x == p2.x && p1.y == p2.y; }



class Solution {
public:
    int maxPoints(vector<Point>& v) {
        if (v.size()==0) return 0;
        vector<Point> & a = v;
        sort(v.begin(), v.end(), cmp);
        int ret = 1;
        for (int i=0; i<v.size(); i++) {
            
            int same = 1;
            map<double, int> mp;
            for (int j=0; j<v.size(); j++) {
                if (i==j)continue;
                if (equaler(v[i], v[j])) {  same++; continue; }
                
                if (a[i].x == a[j].x) {
                    mp[INF] ++;
                } else {
                    double Ki = (a[i].y - a[j].y) * 1.0 / (a[i].x - a[j].x);
                    mp[Ki]++;
                }
            }
```
