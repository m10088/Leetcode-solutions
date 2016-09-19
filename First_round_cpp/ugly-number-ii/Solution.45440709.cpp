
int d[1000];
class Solution {
public:
    int nthUglyNumber(int n) {
        for(auto i=1;i<1000;i++){
            d[i]=1;
        }
        int loc_2=1;
        int loc_3=1;
        int loc_5=1;
        int min2;
        int min3;
        int min5;
        for(auto i=2;i<=n;i++)
        {
            for(auto x=loc_2;;x++)
            {
                if(d[x]*2>d[i-1])
                {
                    loc_2=x;
                    min2=d[loc_2]*2;
                    break;
                }
            }
            for(auto x=loc_3;;x++)
            {
                if(d[x]*3>d[i-1])
                {
                    loc_3=x;
                    min3=d[loc_3]*3;
                    break;
                }
            }
              for(auto x=loc_5;;x++)
            {
                if(d[x]*5>d[i-1])
                {
                    loc_5=x;
                    min5=d[loc_5]*5;
                    break;
                }
            }
            if(min2<=min3&&min2<=min5)
            {
                d[i]=min2;
            }
            if(min3<=min2&&min3<=min5)
            {
                d[i]=min3;
            }
            if(min5<=min2&&min5<=min3)
            {
                d[i]=min5;
            }
        }
       // for(auto x=1;x<10;x++)
       // {
        //    std::cout<<d[x]<<" ";
       // }
        return d[n];
    }
};