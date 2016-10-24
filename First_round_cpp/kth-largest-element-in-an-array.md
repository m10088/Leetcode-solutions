```c++
int patition(int *a,int lo,int hi){
    int piv=a[lo];
    int i=lo,j=hi+1;
    while(true){
        while(a[++i]<piv)if(i==hi)break;
        while(piv<a[--j]);
        if(i>=j)break;
        int tmp=a[i];
        a[i]=a[j];
        a[j]=tmp;
    }
    int tmp=a[lo];
    a[lo]=a[j];
    a[j]=tmp;
    return j;
}

int dfs(int *a,int n,int k){
    
    if(n==1){
        return a[0];
    }
    int mid=patition(a,0,n-1);
    if(k==mid)return a[k];
    else if(k<mid){
        return dfs(a,mid,k);
    }else{
        return dfs(a+mid+1,n-(mid+1),k-mid-1);
    }
}

int findKthLargest(int* nums, int numsSize, int k) {
    return dfs(nums,numsSize,(numsSize-k));
}
```
