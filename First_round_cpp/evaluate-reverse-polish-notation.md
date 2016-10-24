```c++
template<typename T>
T StringTo(const std::string &s){
    std::stringstream sout;
    sout << s;
    T tmp;
    sout >> tmp;
    return tmp;
}

class Solution {
public:
    int evalRPN(vector<string>& v) {
        vector<int> stack;
        for(int i=0;i<v.size();i++){
            if(v[i]=="+"){
                int fir=stack.back();
                stack.pop_back();
                int sec=stack.back();
                stack.pop_back();
                int res=fir+sec;
                
                stack.push_back(res);
            }
            else if(v[i]=="-"){
                int fir=stack.back();
                stack.pop_back();
                int sec=stack.back();
                stack.pop_back();
                int res=sec-fir;
                stack.push_back(res);
            }
            else if(v[i]=="*"){
                int fir=stack.back();
                stack.pop_back();
                int sec=stack.back();
                stack.pop_back();
                int res=fir*sec;
                
                stack.push_back(res);
            }
            else if(v[i]=="/"){
                int fir=stack.back();
                stack.pop_back();
                int sec=stack.back();
                stack.pop_back();
                int res=sec/fir;
                stack.push_back(res);
            }
            else{
                auto tmp=StringTo<int>(v[i]);
```
