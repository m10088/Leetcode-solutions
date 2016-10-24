```c++
#include<sstream>
#include<algorithm>
#define INT_MIN -2147483648
#define INT_MAX 2147483647
bool legal(char x)
{
 return x<='9'&&x>='0'||x=='-'||x=='+';
}

class Solution {
public:
    int myAtoi(string s)
{
       int flag=1;
       auto p=s.begin();
       while(*p==' ')
       {p=s.erase(p);}
       if(legal(*p)==false)return 0;
       if((*p)=='+')
       {
           flag=1;
           p=s.erase(p);
       }
       else if((*p)=='-')
       {
           flag=-1;
           p=s.erase(p);
       }
       if(!((*p)<='9'&&(*p)>='0'))return 0;
       stringstream strm(s);
       long long a;
       strm>>a;
       a=a*flag;
       if(a<INT_MIN)return INT_MIN;
       else if(a>INT_MAX)return INT_MAX;
       else return a;


}

}
```
