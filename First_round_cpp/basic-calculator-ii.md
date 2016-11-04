```c++

template < typename T>
T StringTo(const std::string &s) {
    std::stringstream sout;
    sout << s;
    T tmp;
    sout >> tmp;
    return tmp;
}

class Solution {
    public:
        int calculate(string s) {
            
            for (auto p = s.begin(); p != s.end();) {
                if ((*p) == ' ') {
                    p = s.erase(p);
                    }else{
                    p++;
                }
            }

            vector<string> v;
            string::iterator p = s.begin(),q = p + 1;
            while (p != s.end()) {
                if ((*p)<='9'&&(*p)>='0') {
                    while (q != s.end() && (*q)<='9'&&(*q)>='0') {
                        q++;
                    }
                    v.push_back(string(p, q));
                    p = q;
                    q = p + 1;
                    }else{
                    
                    v.push_back(string(p, q));
                    p = q;
                    q = q + 1;
                }
            }

            vector<string> rev;
            vector<string> stack;
            for (int i = 0; i < v.size(); i++) {
                if (v[i][0]<='9'&&v[i][0]>='0') {
                    rev.push_back(v[i]);
                    }else if(v[i]=="("){
                    stack.push_back("(");
                    }else if(v[i]==")"){
                    while (stack.back() != "(") {
```
