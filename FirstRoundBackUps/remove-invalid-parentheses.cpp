 
//ç§»é¤æ¬å·ï¼ä¹åç¶æè½¬ç§»
bool isvalid(const string &s){
    int lefter=0;
    int righter=0;
    for(int i=0;i<s.size();i++){
        if(s[i]=='(')lefter++;
        else if(s[i]==')'){
            if(lefter==0)return false;
            else lefter--;
        }
    }
    return lefter==righter;
}

struct Node{
  string s;
  int step;
  Node(const string&s,int step):s(s),step(step){}
  Node(){}
};
unordered_map<string,int> vis;
class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
    vis.clear();
    int minmum=10000;
    deque<Node> d;
    vector<string> ans;
    string first=s;
    d.push_back(Node(first,0));
    vis[s]=1;
    int flag=0;//æ è®°ææ²¡ææ¾å°ææçåç´ ï¼å¦ææ¾å°äºææçåç´ å°±ä¸å¨å å¥éåäº
    while(d.empty()==false){
        Node tmp=d.front();
        d.pop_front();
        if(tmp.step>minmum){
            break;//åé¢å¨æ¯å¤§äºç
        }
        
        if(isvalid(tmp.s)){
           minmum=tmp.step;
           ans.push_back(tmp.s);
        }else{

            string &s=tmp.s;
            int &step=tmp.step;

            for(int i=0;i<s.size();i++){
                if(s[i]=='('||s[i]==')'){
                    string tar=string(s.begin(),s.begin()+i)+string(s.begin()+i+1,s.end());
                    if(vis.find(tar)!=vis.end()){}
                    else{
                        d.push_back(Node(tar,step+1));
                        vis[tar]=1;
                    }
                }
            }

       }
    }
    sort(ans.begin(),ans.end());
    ans.erase(unique(ans.begin(),ans.end()),ans.end());
    if(ans.size()==0){
        ans.push_back(string());
    }
    return ans;
}
};