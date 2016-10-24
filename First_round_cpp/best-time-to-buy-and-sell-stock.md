```c++
#define INF 0x3f3f3f3f
class Solution {
public:
    int maxProfit(vector<int>& a) {
        const int k=a.size();
        if(!k)return 0;
        int former_min[k],later_max[k];
        former_min[0]=a[0];
        for(int i=1;i<k;i++){
            if(a[i]<former_min[i-1]){
                former_min[i]=a[i];
            }else{
                former_min[i]=former_min[i-1];
            }
        }
        later_max[k-1]=a[k-1];
        for(int i=k-2;i>=0;i--){
            if(a[i]>later_max[i+1]){
                later_max[i]=a[i];
            }else{
                later_max[i]=later_max[i+1];
            }
        }
        int ans=-INF;
        for(int i=0;i<k;i++){
            ans=std::max(ans,later_max[i]-former_min[i]);
        }
        
        return ans;
    }
}
```
