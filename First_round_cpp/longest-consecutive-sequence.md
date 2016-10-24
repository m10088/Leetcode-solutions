```c++
unordered_map<int,int> fa;
unordered_map<int,int> mark;
int get(int i){
    int ans=1;
    while(fa[i]!=i){
        ans++;
        i=fa[i];
    }
    return ans;
}
class Solution {
public:
    int longestConsecutive(vector<int>& a) {
        fa.clear();
        mark.clear();
        for(int i=0;i<a.size();i++){
            if(fa.find(a[i]+1)!=fa.end()){
                fa[a[i]]=a[i]+1;
                mark.erase(a[i]+1);
                mark[a[i]]=1;
            }else{
                fa[a[i]]=a[i];
                mark[a[i]]=1;
            }
            
            if(fa.find(a[i]-1)!=fa.end()){
                fa[a[i]-1]=a[i];
                mark.erase(a[i]);
            }
        }
        
        int maxer=0;
        for(auto p=mark.begin();p!=mark.end();p++){
            maxer=std::max(maxer,get(p->first));
        }
        return maxer;
    }
    
}
```
