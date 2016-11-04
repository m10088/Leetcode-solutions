```c++
class Solution {
    public:
        int wiggleMaxLength(vector<int>& v) {
            if (v.size() == 0) return 0;
            if (v.size()<=2) return 1;
            int n = v.size();
            
            int dir = 0;
            int i;
            for (i = 0; i < v.size() - 1; i++) {
                if (v[i] < v[i + 1]) {
                    dir = 1;
                    break;
                    } else if (v[i] > v[i+1]) {
                    dir = -1;
                    break;
                }
            }
            if (dir == 0) return 1;
            
            int cnt = 2;
            int last = v[i + 1];
            for (i = i + 2; i < n; i++) {
                if (v[i] == last) {}
                else if (v[i] > last) {
                    if (dir == 1) { last = v[i]; }
                    else {
                        dir = 1;
                        cnt ++;
                        
                        last = v[i];
                    }
                    } else if (v[i] < last) {
                    if (dir == -1) { last = v[i]; }
                    else {
                        dir = -1;
                        cnt++;
                        
                        last = v[i];
                    }
                }
            }
            return cnt;
        }
}
```
