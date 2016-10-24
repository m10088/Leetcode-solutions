```c++
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        
        
        vector<int> res;
        vector<int> &v=nums;
        int fir=0,sec=0;
        int firstcounter=0,secondcounter=0;
        for(int i=0;i<v.size();i++){
            if(v[i]==fir)firstcounter++;
            else if(v[i]==sec)secondcounter++;
            else if(firstcounter==0) fir=v[i],firstcounter=1;
            else if(secondcounter==0) sec=v[i],secondcounter=1;
            else firstcounter--,secondcounter--;
        }
        firstcounter=secondcounter=0;
        for(int i=0;i<v.size();i++){
            if(v[i]==fir)firstcounter++;
            else if(v[i]==sec)secondcounter++;
            else {}
        }
        if(firstcounter>(v.size()/3))res.push_back(fir);
        if(secondcounter>v.size()/3)res.push_back(sec);
        return res;
    }
}
```
