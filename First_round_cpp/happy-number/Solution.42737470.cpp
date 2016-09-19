class Solution {
public:
    bool isHappy(int x) {
           if(x==0)return false;
    int res=0;
    while(x)
    {
        res+=(x%10)*(x%10);
        x=x/10;
    }
    if(res>=2&&res<=9)return false;
    else if(res==1)return true;
    else return isHappy(res);
    }
};