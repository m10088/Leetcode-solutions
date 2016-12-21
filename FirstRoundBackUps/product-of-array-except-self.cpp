class Solution {
public:
    vector<int> productExceptSelf(vector<int>& v) {
         vector<int>res;
            int i=count(v.begin(),v.end(),0);
            if(i>=2)
            return vector<int>(v.size());
            else if(i==1)
            {
                int sum=1;
                for(int i=0;i<v.size();i++)
                {
                    if(v[i])
                    sum*=v[i];
                }
                for(auto i=0;i<v.size();i++)
                {
                    if(v[i])
                    {
                        res.push_back(0);
                        
                    }
                    else
                        res.push_back(sum);
                }
                return res;
                
            }
            
            else
            {
                int sum=1;
                for(int i=0;i<v.size();i++)
                {
                    if(v[i])
                    sum*=v[i];
                }
                for(auto i=0;i<v.size();i++)
                {
                    if(v[i])
                    {
                        res.push_back(sum/v[i]);
                        
                    }
                    else
                        res.push_back(sum);
                }
                return res;
            }
    }
};