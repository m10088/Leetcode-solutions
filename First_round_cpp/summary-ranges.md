```c++
#include<sstream>
#include<string>

class Solution {
    public:
        vector<string> summaryRanges(vector<int>& v) {
            vector<string> res;
            if (v.size() == 0){return res;}
            std::string s;
            stringstream strm(s);
            int b, e;
            b = e = v[0];
            for (int i = 0; i < v.size(); i++) {
                if (i + 1 == v.size()) {
                    if (b == e) {
                        strm << b;
                        res.push_back(strm.str());
                        strm.str("");
                    }
                    else
                    {
                        strm << e << "->" << b;
                        res.push_back(strm.str());
                        strm.str("");
                    }
                    break;
                }
                else
                {
                    if (v[i + 1] == b + 1)
                    {b++;continue;}
                    else
                    {
                        if (b == e) {
                            strm << b;
                            res.push_back(strm.str());
                            strm.str("");
                        }
                        else
                        {
                            strm << e << "->" << b;
                            res.push_back(strm.str());
                            strm.str("");
                        }
                        b = e = v[i + 1];
                    }
                }
            }
            return res;
        }
```
