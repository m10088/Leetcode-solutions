```c++
 

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
    int flag=0;
    while(d.empty()==false){
        Node tmp=d.front();
        d.pop_front();
        if(tmp.step>minmum){
            break;
        }
        
        if(isvalid(tmp.s)){
           minmum=tmp.step;
           ans.push_back(tmp.s);
        }else{

            string &s=tmp.s;
            int &step=tmp.step;

            for(int i=0;i<s.size();i++){
                if(s[i]=='('||s[i]==')'){
```
