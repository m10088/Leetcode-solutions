#include<algorithm>
int f(string s,int m,int x)
{
    if(m==s.size())
    return s[m-x]-48;
    else
    {
        if(x>s.size())
        return 0;
        else
        {
            return s[s.size()-x]-48;
        }
    }
}
class Solution {
public:
    string addBinary(string s, string t) {
        if(s.empty()&&t.empty())return "0";
         if(!s.empty()&&t.empty())return s;
         if(!t.empty()&&s.empty())return t;
       
       
        
        int m=std::max(s.size(),t.size());
        string res;
        int j=0;
        for(int i=1;i<=m;i++)
        {
            if(f(s,m,i)+f(t,m,i)+j==3)
            {
                res.push_back('1');
                j=1;
            }
           else if(f(s,m,i)+f(t,m,i)+j==2)
            {
                res.push_back('0');
                j=1;
            }
            else
            {
                if(f(s,m,i)+f(t,m,i)+j==1)
                res.push_back('1');
                else
                res.push_back('0');
                j=0;
            }
        }
        if(j)
        res.push_back('1');
        reverse(res.begin(),res.end());
        return res;
    }
};