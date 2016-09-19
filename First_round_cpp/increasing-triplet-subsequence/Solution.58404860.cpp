class Solution {
public:
     bool increasingTriplet(vector<int>& nums)
        {   

            vector<int>::iterator it;
            int min = INT_MAX;
            for(it = nums.begin(); it < nums.end(); it++) {
                if(*it <= min) {
                    min = *it;
                    *it = INT_MIN;//i feel there should not be such element...
                }
            }
            vector<int>::reverse_iterator rit = nums.rbegin();
            int max = INT_MIN;
            for(; rit < nums.rend(); rit++) {
               if (*rit >= max && *rit != INT_MIN) {
                   max = *rit;
               } else if (*rit != INT_MIN){
                   return true;
               }
            }
            return false;                                                                                                                                                   
        }
};