#include<math>
class Solution {
public:
    long long  computeArea(int a, int b, int c, int d, int e, int f, int g, int h) {
        long long  m1=max(max(a,c),max(e,g));
        long long m2=min(min(a,c),min(e,g));
        long long lenth;
        if(fabs(c-a)+fabs(g-e)<m1-m2){lenth=0;}
        else lenth=fabs(c-a)+fabs(g-e)-(m1-m2);
        
        long long n1=max(max(b,d),max(f,h));
        long long n2=min(min(b,d),min(f,h));
        long long wid;
        if(fabs(d-b)+fabs(h-f)<n1-n2) wid=0;
        else wid=fabs(d-b)+fabs(h-f)-(n1-n2);
        
       long long jiao=lenth*wid;
        
        long long res=fabs(c-a)*fabs(d-b)+fabs(g-e)*fabs(h-f)-jiao;
        return int(res);
    }
};