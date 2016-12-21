struct Node{
    int id;
    int x;
    Node(int id,int x):id(id),x(x){}
    Node(){}
};
bool cmp(const Node&n1,const Node&n2){
    return n2.x<n1.x;//ä¼åéæ©
}
bool can(int b,vector<int>& gas, vector<int>& cost){//ä»bå¼å§è½ä¸è½éåå®æ
    
    int accu=0;
    int n=gas.size();
    int cnt=0;
    while(1){
        
        if(gas[b]+accu>=cost[b]){//è¿ä¸ªå æ²¹ææ¯å¯ä»¥ç
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
        //åè¿æ§å¤çä¹ååè¿è¡æ¨¡æ
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
        // int lo=0,hi=n,res,mid;
        // while(lo<hi){
        //     mid=lo+(hi-lo)/2;
        //     if(can(a[mid].id,gas,cost)==false){
        //         lo=mid+1;
        //         res=lo;
        //     }else{
        //         hi=mid;
        //         res=hi;
        //     }
        // }
        // if(res==n)return -1;
        // else return a[res].id;
    }
};