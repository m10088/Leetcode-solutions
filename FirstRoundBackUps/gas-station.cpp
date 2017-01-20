struct Node{
    int id;
    int x;
    Node(int id,int x):id(id),x(x){}
    Node(){}
};
bool cmp(const Node&n1,const Node&n2){
    return n2.x<n1.x;
}
bool can(int b,vector<int>& gas, vector<int>& cost){
    
    int accu=0;
    int n=gas.size();
    int cnt=0;
    while(1){
        
        if(gas[b]+accu>=cost[b]){
            cnt++;
            if(cnt==n)return true;
            
            accu=gas[b]+accu-cost[b];
            b=(b+1)%(n);
        }else{
            return false;
        }
    }
}
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        
        int n=gas.size();
        if(n==0)return -1;
        if(n==1){
            if(gas[0]>=cost[0]){
                return 0;
            }else{
                return -1;
            }
        }
        
        Node*a=new Node[n];
        for(int i=0;i<n;i++){
            a[i].id=i;
            a[i].x=gas[i]-cost[i];
        }
        sort(a,a+n,cmp);
        for(int i=0;i<n;i++){
            if(can(a[i].id,gas,cost)){
                return a[i].id;
            }
        }
        return -1;
        
        
        
        
        
        
        
        
        
        
        
        
        
    }
};