```c++
void adder(vector<int>&res,int k,int val){
    while(k--){
        res.push_back(val);
    }
}
map<int,int> fir,sec;
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        fir.clear();
        sec.clear();
       for(int i=0;i<nums1.size();i++){
           fir[nums1[i]]++;
       }
       for(int i=0;i<nums2.size();i++){
           sec[nums2[i]]++;
       }
       vector<int> res;
       for(auto p=fir.begin();p!=fir.end();p++){
           auto val=p->first;
           auto q=sec.find(val);
           if(q==sec.end())continue;
           else adder(res,std::min(p->second,q->second),val);
       }
       return res;
    }
};
```
