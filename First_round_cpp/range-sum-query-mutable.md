```c++
class NumArray {

public:
    struct Node  {  
        int l,r,val;  
        int lazy; 
    };
    int n,m,x,y,z,type,*a;
    Node* t;
    void pushdown(int i){  
        t[i<<1].val+=t[i].lazy*(t[i<<1].r-t[i<<1].l+1);  
        t[(i<<1)+1].val+=t[i].lazy*(t[(i<<1)+1].r-t[(i<<1)+1].l+1);  
        t[i<<1].lazy+=t[i].lazy,t[(i<<1)+1].lazy+=t[i].lazy,t[i].lazy=0;  
    }  
    void build(int l,int r,int i){  
        t[i].l=l;  
        t[i].r=r;  
        if(l==r)  
            t[i].val=a[l];  
        else  
        {  
            int mid=(l+r)>>1;  
            build(l,mid,i<<1);  
            build(mid+1,r,(i<<1)+1);  
            t[i].val=t[i<<1].val+t[(i<<1)+1].val;  
        }  
    }  
    void update(int x,int l,int r,int i,int val){  
        if(l==r)  
            t[i].val=val;  
        else  
        {  
            pushdown(i);  
            int mid=(l+r)>>1;  
            if(x<=mid)  
                update(x,l,mid,i<<1,val);  
            else  
                update(x,mid+1,r,(i<<1)+1,val);  
            t[i].val=t[i<<1].val+t[(i<<1)+1].val;  
        }  
    }  
    int query(int tl,int tr,int l,int r,int i) {  
        if(tl<=l && r<=tr) return t[i].val;  
        if(tl>r || tr<l) return 0;  
          
        pushdown(i);  
        int mid=(l+r)>>1;  
        return query(tl,tr,l,mid,i<<1)+query(tl,tr,mid+1,r,(i<<1)+1);  
    }  
    NumArray(vector<int> &nums) {
```
