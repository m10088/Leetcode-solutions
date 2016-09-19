class Solution {
public:
    int longestValidParentheses(string s) {
        if(s.size()==0)return 0;
        vector<int>index;
        vector<int>elem;
        index.push_back(-1);
        for(int i=0;i<s.size();i++){
            if(elem.empty()==false&&elem.back()=='('&&s[i]==')'){
                elem.pop_back();
                index.pop_back();
            }else{
                elem.push_back(s[i]);
                index.push_back(i);
            }
        }
        int maxer=-1;
        int end=s.size();
        while(index.empty()==false){
            int begin=index.back();
            index.pop_back();
            maxer=std::max(maxer,end-begin-1);
            end=begin;
        }
        return maxer;
    }
};