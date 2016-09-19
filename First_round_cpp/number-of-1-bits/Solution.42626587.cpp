class Solution {
public:
    int hammingWeight(uint32_t n) {
        short res=0;
        while(n)
        {
            res+=n%2;
            n/=2;
        }
        return res;
    }
};