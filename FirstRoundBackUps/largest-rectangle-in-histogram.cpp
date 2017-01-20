class Solution {
public:
    int largestRectangleArea(vector<int>& v) {
        if(v.size()==0)return 0;
        int res = 0;
        vector<int> stk;
        for(int i=0;i<v.size();i++)
        {
            if(stk.empty()||stk.back()<=v[i])
                stk.push_back(v[i]);
            else
            {
                int count = 0;
                while(!stk.empty()&&stk.back() > v[i])
                {
                    count ++;
                    res = max(res, stk.back()*count);
                    stk.pop_back();
                }
                count++;
                while(count --)
                    stk.push_back(v[i]);
                
            }
        }
        
        
        for(int i=0;i<stk.size();i++){
            
            int tmp=(v.size()-i)*stk[i];
            res=std::max(res,tmp);
        }
        return res;
    }
};