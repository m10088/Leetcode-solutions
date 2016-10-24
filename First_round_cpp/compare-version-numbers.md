```c++
template<typename T>
std::vector<T> StringToVec(const std::string &s){
    std::stringstream sout;
    sout << s;
    std::vector<T> res;
    T tmp;
    char c;
    while(sout >> tmp){
        if(sout>>c)
            res.push_back(tmp);
        else{
            res.push_back(tmp);
            break;
        }
    }
    return res;
}
void Fun(vector<int>&v){
    while(v.back()==0){
        v.pop_back();
    }
}
class Solution {
public:
    int compareVersion(string version1, string version2) {
        vector<int> v1=StringToVec<int>(version1);
        vector<int> v2=StringToVec<int>(version2);
        Fun(v1);
        Fun(v2);
        if(v1==v2){
            return 0;
        }else if(v1>v2){
            return 1;
        }else{
            return -1;
        }
    }
}
```
