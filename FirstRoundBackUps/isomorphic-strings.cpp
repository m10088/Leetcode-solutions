#include<unodered_map>
class Solution {
public:
    bool isIsomorphic(string s, string t) {
       //åè¯»æç½é¢ç®ææï¼æ¯å¯ä»¥ç½®ç¬¬ä¸ä¸ªåºåå¯ä»¥ç½®æ¢æç¬¬äºä¸ªåºåå­æ¯â>åå¸è¡¨
       unordered_map<char,char> tab1;
       unordered_map<char,char> tab2;
       for(int i=0;i<s.size();i++)
       {
           if(tab1.find(s[i])==tab1.end()&&tab2.find(t[i])==tab2.end())
           {tab1[s[i]]=t[i];tab2[t[i]]=s[i];}
           else
           {
               if(!(tab1[s[i]]==t[i]&&tab2[t[i]]==s[i]))return false;
           }
       }
       return true;
    }
};