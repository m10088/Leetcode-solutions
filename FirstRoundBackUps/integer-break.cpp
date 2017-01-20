vector<int> partation(int x,int n){
    if(n>x) return vector<int>();
   
    int offset=x/n;
    int mod=x%n;
    vector<int> res;
    for(int i=0;i<mod;i++){
        res.push_back(offset+1);
    }
    for(int i=0;i<(n-mod);i++){
        res.push_back(offset);
    }
    return res;
}

class Solution {
public:
    int integerBreak(int n) {
        if(n==0)return 0;
        if(n==1)return 0;
        if(n==2)return 1;
        if(n==3)return 2;
        long double mid=n*1.0/2.718281828459045235360287471;
        int maxer=-1;
        for(int i=mid-2;i<mid+2;i++){
            if(i<2)continue;
            vector<int> tmp=partation(n,i);
            int ans=1;
            for(int i=0;i<tmp.size();i++){
                ans*=tmp[i];
            }
            maxer=std::max(maxer,ans);
        }
        return maxer;
    }
};