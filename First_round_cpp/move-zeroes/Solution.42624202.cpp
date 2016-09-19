class Solution {
public:
    void moveZeroes(vector<int>& a) {
        
        for(auto j=0;j<a.size()-1;j++)
        {
            for(auto i=0;i<a.size()-1-j;i++)
            {
                if(!a[i]&&a[i+1])
                   std::swap(a[i],a[i+1]);
            }
        }
    }
};