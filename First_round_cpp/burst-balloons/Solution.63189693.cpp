//å¨å·¦ç«¯ç¹æ¯iï¼å³ç«¯ç¹æ¯jçæåµçä¸ï¼å·¦è¾¹å©ä½çåç´ çlï¼å³è¾¹å©ä½çåç´ æ¯rçæåµä¸çæå¤§æ¶ç
struct Node{
    short i,j,r,l;//i,jæ¯ç´¢å¼,r,læ¯å¼
    Node(int i,int j,int l,int r):i(i),j(j),l(l),r(r){}
    Node(){}
    bool operator == (const Node&n)const{
        return n.i==i&&n.j==j&&n.l==l&&n.r==r;
    }
};
namespace std {
 template <>
 struct hash<Node>
 {
 std::size_t operator()(const Node& k) const
 {
  using std::size_t;
  using std::hash;
  using std::string;
  // Compute individual hash values for first,
  // second and third and combine them using XOR
  // and bit shifting:
  return k.i*k.j*k.l*k.r;

 }
 };
}
unordered_map<Node,int> m;

int dfs(vector<int>& nums,int i,int j,int l,int r){
    
    vector<int>&v=nums;
    Node tmp=Node(i,j,l,r);
    if(m.find(tmp)!=m.end())return m[tmp];
    if(i==j)return m[tmp]=nums[i]*l*r;//å¦ææ¯1ä¸ªåç´ ç´æ¥å¤æ­æ¶ç
    else{//å¦ææ¯å¤ä¸ªåç´ 
        int maxer=-1;
        for(int k=i;k<=j;k++){
            if(k==i){//å·¦è¾¹æ²¡ææ¶ç
                maxer=std::max(maxer,dfs(nums,k+1,j,v[k],r)+v[k]*l*r);
            }else if(k==j){
                maxer=std::max(maxer,dfs(nums,i,k-1,l,v[k])+v[k]*l*r);
            }else{
                maxer=std::max(maxer,dfs(nums,i,k-1,l,v[k])+dfs(nums,k+1,j,v[k],r)+v[k]*l*r);
            }
        }
        return m[tmp]=maxer;
    }
}
class Solution {
public:
    int maxCoins(vector<int>& nums) {
        m.clear();
        if(nums.size()==0)return 0;
        return dfs(nums,0,nums.size()-1,1,1);               
    }
};