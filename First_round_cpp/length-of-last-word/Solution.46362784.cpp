class Solution {
public:
    int lengthOfLastWord(string s) {
       if(s.size()==0)return 0;
        if(s==" ")return 0;
        
        auto p=s.end()-1;
        while((*p)==' '&&p!=s.begin())
        {
            p--;
        }
        
        if(p==s.begin())
        {
            if((*p)==' ')return 0;
            else return 1;
        }
        
        int i=0;
        while(1)
        {
            if(p==s.begin())
                {
                    if((*p)!=' ')
                    {i++;return i;}
                    else
                    return i;
                }
                
            if((*p)!=' ')
                i++;
            else
                return i;
            p--;
        }
    }
};