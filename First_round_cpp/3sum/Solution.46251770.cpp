class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& v) {
        vector<vector<int>>res;
        int sz=v.size();
        if(sz<3)return res;
        
        std::sort(v.begin(),v.end());
        
        for(int i=0;i<v.size()-2;i++)
        {
            if(i!=0&&v[i]==v[i-1])//don't need sovle it.
            {
                continue;
            }
            else 
            {
                int p=i+1;
                int q=sz-1;
                while(p!=q)
                {
                    if(v[i]+v[q]+v[p]==0)
                    {
                        res.push_back(vector<int>{v[i],v[p],v[q]});
                        int flag=0;
                        do
                        {
                            p++;
                            if(p==q)
                            {
                                flag=1;
                                break;
                            }
                        }while(v[p]==v[p-1]);
                        
                        if(flag==1)break;
                        
                        
                    }
                    else if(v[i]+v[q]+v[p]>0)
                    {
                        q--;
                    }
                    else
                    {
                        p++;
                    }
                }
            }
        }
        return res;
    }
};