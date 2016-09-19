#include<map>
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& v, int k) {
        if(v.size()==0)return false;
    map<int,int> m;
    map<int,int> info;
    int flag=0;
    for(int i=0;i<v.size();i++)
    {
        if(m.find(v[i])==m.end())
        {
            m.insert(pair<int,int>(v[i],i));
        }
        else
        {
            flag=1;
            if((i-m[v[i]])>k)
                {
                    
                    if(info.find(v[i])==info.end())
                    {
                        info.insert(make_pair(v[i],i-m[v[i]]));
                    }
                    else
                    {
                        if(i-m[v[i]]<info[v[i]])
                        {
                            info[v[i]]=i-m[v[i]];
                        }
                    }
                    m[v[i]]=i;
                }
                
            else
                return true;
        }
    }
    if(flag==1)
        {
            for(auto&m:info)
            {
                if(m.second>k)return false;
            }
            
        }
        
    else
        return false;
    }
};