```c++
template<typename T>
T StringTo(std::string s) {
    if (s.size()==0) return 0;
    std::stringstream sout;
    sout << s;
    T tmp;
    sout >> tmp;
    return tmp;
}
template<typename T>
std::string ToString(T x){
    std::stringstream sout;
    sout << x;
    return sout.str();
}

string sp(string s, int i, int j) { return string(s.begin()+i, s.begin()+j); }

int ax(int x) {
    int ret = 1;
    for (int i=0; i<x; i++) ret = ret * 10;
    return ret;
}


int fx(string s, int i) {
    if (i==0) {
        if (s[i]=='1') {
            return StringTo<int> (sp(s, i+1, s.size())) + 1;
        } else {
            return ax(s.size()-1);
        }
    } else {
        int former = StringTo<int>(sp(s,0,i));
        if (s[i]=='1') {
            return StringTo<int> (sp(s, i+1, s.size())) + 1 + (former) * ax(s.size()-1-i);
        } else if (s[i]=='0') {
            return (former) * ax(s.size()-1-i);
        } else {

            return (former + 1) * ax(s.size()-1-i);
        }
    }

    return 0;
}

class Solution {
public:
    int countDigitOne(int x) {
```
