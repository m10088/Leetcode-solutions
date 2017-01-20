#include<set>
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& v) {
      
        vector< vector<int> > res;
        
        int sz=v.size();
        for(int i=0;i<1<<sz;i++)
        {
            vector<int> path;
            for(int j=0;j!=sz;j++)
            {
                if(i&(1<<j))
                {
                    path.push_back(v[j]);
                }
                std::sort(path.begin(),path.end());
            }
            res.push_back(path);
            
        }
        set< vector<int> > s;
        s.insert(res.begin(),res.end());
        vector <vector<int> > res_;
        std::copy(s.begin(),s.end(),back_inserter(res_));
        
        
        return res_;
    }
};