#define N 15000
vector<int> G[N];
int d[N];
int mark[N];


class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
        vector<int> res;
        for(int i=0;i<N;i++){G[i].clear();}
        memset(mark,0,sizeof(mark));
        memset(d,0,sizeof(d));
        
        for(int i=0;i<edges.size();i++){
            auto first=edges[i].first;
            auto second=edges[i].second;
            G[first].push_back(second);G[second].push_back(first);
            d[first]++;
            d[second]++;
        }
        vector<int> d_is_one;
        vector<int> d_is_zero;
        bool stopflag=false;
        
        while(stopflag==false){
            
            
            d_is_one.clear();
            d_is_zero.clear();
            int lefter=0;
            for(int i=0;i<n;i++){
                if(mark[i]!=-1){
                    lefter++;
                    if(d[i]==1){
                        mark[i]=-1;
                        d_is_one.push_back(i);
                    }else if(d[i]==0){
                        mark[i]=-1;
                        d_is_zero.push_back(i);
                    }   
                }
            }
            if(d_is_zero.size()==1){
                return d_is_zero;
            }
            if(d_is_one.size()==2&&lefter==2){
                return d_is_one;
            }
            
            for(int i=0;i<d_is_one.size();i++){
                auto & x=d_is_one[i];
                
                for(int j=0;j<G[x].size();j++){
                    if(mark[G[x][j]]!=-1){
                        d[G[x][j]]--;
                    }
                }
            }
            
        }
        return res;
        
        
    }
};