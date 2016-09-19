
class Solution {
public:
   vector<int> singleNumber(vector<int>& nums) {
        int AxorB = 0;
        for(int i = 0;i<nums.size();i++){
            AxorB^=nums[i];
        }
        //åæåä¸ä¸ªäºè¿å¶ä½
        int mask = AxorB & (~(AxorB-1));
        int A = 0,B = 0;
        for(int i = 0;i<nums.size();i++){
            if(mask&nums[i])
                A ^= nums[i];
            else
                B ^= nums[i];
        }

        return vector<int>({A,B});
    }
};