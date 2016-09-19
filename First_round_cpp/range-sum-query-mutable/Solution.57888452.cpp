class NumArray {

public:
    struct Node  {  
        int l,r,val;  
        int lazy; //è¥ä¸éè¦åºé´æ´æ°ï¼åå¯ä»¥å»æ;pushdownå½æ°ï¼ä»¥åææå¯¹å¶çè°ç¨ï¼ä¹ä¸å¹¶å»æ  
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
        if(nums.size()==0)return;
        int N=nums.size()+7;
        n=nums.size();
        a=new int[N+10];
        t=new Node[(N<<2)+10];
        for(int i=0;i<nums.size();i++){
            a[i+1]=nums[i];
        }
        build(1,n,1);
    }
    void update(int i, int val) {
        update(i+1,1,n,1,val);
    }
    int sumRange(int i, int j) {
        return query(i+1,j+1,1,n,1);
    }
};


// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.update(1, 10);
// numArray.sumRange(1, 2);