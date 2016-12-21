#include<sstream>
#include<algorithm>
#define INT_MIN -2147483648
#define INT_MAX 2147483647
class Solution {
public:
    int reverse(long long  x) {
        long long flag=1;
        string word;
        stringstream strm(word);
        if(x<0)
        {
            flag=-1;
            x=-x;
        }
        while(x)
        {
            strm<<x%10;
            x=x/10;
        }
         long long r;
         strm>>r;
         r=r*flag;
         if(r>INT_MAX||r<INT_MIN)return 0;
         else return r;
        
    }
};