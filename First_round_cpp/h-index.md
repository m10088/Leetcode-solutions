```c++
class Solution {
public:
    int hIndex(vector<int>& v) {
        if(v.size()==0)return 0;
        sort(v.begin(),v.end(),[](const int&n1,const int &n2){return n1>n2;});
        for(int i=v.size()-1;i>=0;i--){
            if(v[i]-(i+1)>=0)return i+1;
        }
    }
}
```
