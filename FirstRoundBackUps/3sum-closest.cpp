#include<math.h>
#define INF 0x3f3f3f3f
#include<algorithm>
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        
        std::sort(nums.begin(),nums.end());
        vector<int> res;
        for(int i=0;i<nums.size()-2;i++){
            int fir=i+1,sec=nums.size()-1,tar=target-nums[i];
            int min_dis=INF,answer=INF;
            while(fir<sec){
                int ans=nums[fir]+nums[sec];
                if(ans==tar){answer=ans;break;}
                if(abs(tar-ans)<min_dis){
                    min_dis=abs(tar-ans);
                    answer=ans;
                }
                if(ans<tar){
                    fir++;
                }else{
                    sec--;
                }
            }
            res.push_back(answer+nums[i]);
          
        }
        
        int index=-1,miner=INF;
        for(int i=0;i<res.size();i++){
            if(abs(target-res[i])<miner){
                miner=abs(target-res[i]);
                index=i;
            }
        }
        return res[index];
    }
};