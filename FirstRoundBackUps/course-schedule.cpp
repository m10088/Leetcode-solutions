#define N 3007
int in[N];
vector<int> G[N];
class Solution {
public:
    bool canFinish(int n, vector<pair<int, int>>& v) {
        sort(v.begin(),v.end());
        auto diff=unique(v.begin(),v.end());
        memset(in,0,sizeof(in));
        for(int i=0;i<N;i++){G[i].clear();}
        for(int i=0;i<v.size()-(v.end()-diff);i++){
            G[v[i].second].push_back(v[i].first);
            in[v[i].first]++;
        }
       
        bool visited[N];
        memset(visited,0,sizeof(visited));
        
        for(int i=0;i<n;i++){
            if(visited[i]==false&&in[i]==0){
                
                vector<int> stack;
                visited[i]=true;
                stack.push_back(i);
                while(stack.empty() == false){
                    int tmp = stack.back();
                    stack.pop_back();
                    int flag = 0;
                    for(int i=0;i<G[tmp].size();i++){
                        in[G[tmp][i]]--;
                        if(in[G[tmp][i]]==0){
                            visited[G[tmp][i]]=true;
                            stack.push_back(G[tmp][i]);
                        }
                    }
                    
                }
            }
        }
        for(int i=0;i<n;i++){
            if(visited[i]==false){
                return false;
            }
        }
        return true;
    }
        
    
};