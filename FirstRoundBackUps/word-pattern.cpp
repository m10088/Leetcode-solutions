#include<sstream>

class Solution {
public:
    bool wordPattern(string pattern, string t) {
        unordered_map<char,string> info1;
        unordered_map<string,char> info2;
        stringstream strm;
        strm.str(t);
        string tmp;
        vector<string> v;
        while(strm>>tmp)
        {
            v.push_back(tmp);

        }

        if(v.size()!=pattern.size())
                return false;


        for(int i=0;i<v.size();i++)
        {

            auto p=info1.find(pattern[i]);
            auto q=info2.find(v[i]);
            if(p==info1.end()&&q==info2.end())
            {

                info1[pattern[i]]=v[i];
                info2[v[i]]=pattern[i];
            }
            else
            {
                if(info1[pattern[i]]!=v[i])
                    return false;
                if(info2[v[i]]!=pattern[i])
                    return false;
            }

        }
        return true;
    }
};