int largestRectangleArea(vector<int>& v) {
        if(v.size()==0)return 0;
        int res = 0;
        vector<int> stk;
        for(int i=0;i<v.size();i++)
        {
            if(stk.empty()||stk.back()<=v[i])
                stk.push_back(v[i]);
            else
            {
                int count = 0;
                while(!stk.empty()&&stk.back() > v[i])
                {
                    count ++;
                    res = max(res, stk.back()*count);
                    stk.pop_back();
                }
                count++;
                while(count --)
                    stk.push_back(v[i]);
                
            }
        }
        
        
        for(int i=0;i<stk.size();i++){
            
            int tmp=(v.size()-i)*stk[i];
            res=std::max(res,tmp);
        }
        return res;
}

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& v) {
        int n=v.size();
        if(!n)return 0;
        int m=v[0].size();
        vector<vector<int> > a(n);
        for(int i=0;i<n;i++){
            a[i].resize(m);
        }
        
        for(int j=0;j<m;j++){
            if(v[0][j]=='1'){
                a[0][j]=1;
            }else{
                a[0][j]=0;
            }
        }
        int ret = largestRectangleArea(a[0]);
        for(int i=1;i<n;i++){
            for(int j=0;j<m;j++){
                if(v[i][j]=='0'){
                    a[i][j]=0;
                }else{
                    a[i][j]=a[i-1][j]+1;
                }
                
            }
            ret = max(ret,largestRectangleArea(a[i]));
        }
        
        return ret;
    }
};