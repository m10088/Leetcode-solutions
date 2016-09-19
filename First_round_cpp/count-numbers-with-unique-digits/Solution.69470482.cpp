
int a[100];
class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if (n==0) return 1;
        a[1] = 10;
        //a[2] = 9 * 9;
        //a[3] = 9 * 9 * 8;
        for(int i=2; i<100; i++) {
            a[i] = 9;
            int x = i-1, fac = 9;
            while (x) { a[i] *= fac; fac--; x--; }
        }
        int ans = 0;
        for (int i=1; i<=n; i++) {
            ans += a[i];        
        }
        return ans;
        
        
    }
};