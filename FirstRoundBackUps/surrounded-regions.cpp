
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};

bool legal(vector<vector<char>>& v,int i,int j){
    if(i<v.size()&&i>=0&&j<v[0].size()&&j>=0)
        return true;
    else
        return false;
}

void bfs(vector<vector<char>>&v,int i,int j){
    v[i][j]='.';
    deque<pair<int,int>>d;
    d.push_back(pair<int,int>(i,j));
    while(d.empty()==false){
        auto top=d.front();
        d.pop_front();
        int x=top.first,y=top.second;
        
        for(int k=0;k<4;k++){
            if(legal(v,x+dx[k],y+dy[k])&&v[x+dx[k]][y+dy[k]]=='O'){
                d.push_back(pair<int,int>(x+dx[k],y+dy[k]));
                v[x+dx[k]][y+dy[k]]='.';
            }
        }
    }
}

class Solution {
public:
    void solve(vector<vector<char>>& v) {
       
       if(v.size()==0)return;
       int n=v.size(),m=v[0].size();
       for(int i=0;i<m;i++){
           if(v[0][i]=='O'){
               bfs(v,0,i);
           }
       }
       for(int i=0;i<m;i++){
           if(v[n-1][i]=='O'){
               bfs(v,n-1,i);
           }
       }
       
       for(int i=0;i<n;i++){
           if(v[i][0]=='O'){
               bfs(v,i,0);
           }
       }
       for(int i=0;i<n;i++){
           if(v[i][m-1]=='O'){
               bfs(v,i,m-1);
           }
       }
       for(int i=0;i<n;i++){
           for(int j=0;j<m;j++){
               if(v[i][j]=='.'){
                   v[i][j]='O';
               }else if(v[i][j]=='O'){
                   v[i][j]='X';
               }
           }
           
       }
       
    }
};