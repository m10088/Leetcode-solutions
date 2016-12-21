class Solution {
public:
    int candy(vector<int>& r) {
        vector<int> fir(r.size(),1);
        vector<int> sec(r.size(),1);
        for(int i=1;i<r.size();i++){
            if(r[i]>r[i-1]){
                fir[i]=fir[i-1]+1;
            }
        }
        for(int i=r.size()-2;i>=0;i--){
            if(r[i]>r[i+1]){
                sec[i]=sec[i+1]+1;
            }
        }
        int ans=0;
        for(int i=0;i<r.size();i++){
            ans+=std::max(fir[i],sec[i]);
        }
        return ans;
        
    }
};