int dx[4]={-1,0,1,0};
int dy[4]={0,1,0,-1};

bool is_legal(vector<vector<char> >&v,int x,int y,int n,int m){
    if(x<0||x>n-1||y<0||y>m-1)return false;
    if(v[x][y]=='.')return false;
    else return true;
}

bool dfs(vector<vector<char>>&v,int x,int y,int cur,const string&word){
    if(cur==word.size()-1)
        return true;
    char tmp=v[x][y];
    v[x][y]='.';
    for(int k=0;k<4;k++){
        if(is_legal(v,x+dx[k],y+dy[k],v.size(),v[0].size())){
            if(v[x+dx[k]][y+dy[k]]==word[cur+1]){
                if(dfs(v,x+dx[k],y+dy[k],cur+1,word)){
                    return true;
                }
            }
        }
    }
    v[x][y]=tmp;
    return false;
}

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        if(board.size()==0)return false;
        vector<pair<int,int> > loc;
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]==word[0]){
                    loc.push_back(pair<int,int>(i,j));
                }
            }
        }
        for(int i=0;i<loc.size();i++){
            if(dfs(board,loc[i].first,loc[i].second,0,word)){
                return true;
            }
        }
        return false;
    }
};