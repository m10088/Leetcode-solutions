
class Solution {
public:
   vector<int> singleNumber(vector<int>& nums) {
        int AxorB = 0;
        for(int i = 0;i<nums.size();i++){
            AxorB^=nums[i];
        }
        //åæåä¸ä¸ªäºè¿å¶ä½ææçæ°
        int mask = AxorB & (~(AxorB-1));
        //å¦ææ¯12-ã4
        //éè¿æåä¸ä¸ª1ï¼å¯ä»¥åºåä¸¤ä¸ªæ°
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