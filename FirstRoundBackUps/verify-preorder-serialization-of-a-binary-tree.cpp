#define N 1007
class Solution {
public:
    bool isValidSerialization(string s) {
        vector<string> res;
        s+=',';
        auto p=s.begin();
        auto q=s.begin();
        while(p!=s.end()){
            while((*q)!=','){
                q++;
            }
            res.push_back(string(p,q));
            p=q+1;
            q=p;
        }
        
        if(res.size()==1&&res[0]=="#")return true;
        if(res.size()<3){
            return false;
        }
        if(res[0]=="#")return false;
        vector<string> tmp;
        int flag=0;
        int cur=res.size();
        
        while(1){
            
            if(cur>=3&&res[cur-1]=="#"&&res[cur-2]=="#"&&res[cur-3]=="#"){
                tmp.push_back("#");
                cur-=1;
                if(cur<=0)break;
            }else if(cur>=2&&res[cur-1]=="#"&&res[cur-2]=="#"){
                cur-=3;
                if(cur<=0)break;
                res[cur++]="#";
            }else if(cur>=1&&res[cur-1]=="#"){
                
                if(tmp.empty()==true)
                    return false;
                tmp.pop_back();
                res[cur++]="#";
                
            }else{
                return false;
            }
        }
        if(tmp.size()==0)
            return true;
        else 
            return false;
    }
};