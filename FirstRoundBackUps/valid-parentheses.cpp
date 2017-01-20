class Solution {
public:
    bool isValid(string s) {
        
        vector<char> t;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='{'||s[i]=='('||s[i]=='[')
            {
                t.push_back(s[i]);
            }
            else
            {
                switch(s[i])
                {
                    case '}':
                    {
                       if(t.size()==0||t.back()!='{')
                            return false;
                       else
                       {
                           t.pop_back();
                       }
                       break;
                    }
                    case ')':
                    {
                        if(t.size()==0||t.back()!='(')
                            return false;
                       else
                       {
                           t.pop_back();
                       }
                       break;
                    }
                    case ']':
                    {
                        if(t.size()==0||t.back()!='[')
                             return false;
                       else
                       {
                           t.pop_back();
                       }
                       break;
                    }
                }
            }
        }
        if(t.size()==0)
            return true;
        else
            return false;
    }
};