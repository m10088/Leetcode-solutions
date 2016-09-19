
long long mergerandget(vector<long long>&a,long long lo,long long mid,long long hi,long long L,long long R){
    if(lo+1==hi) return 0;
    long long res=0;
    for(long long i=mid;i<hi;i++){
        long long s = a[i]-R;
        long long t = a[i]-L;
        //å¨å·¦è¾¹çåºé´åå¯»æ¾s<=x<=tçä¸ªæ°
        res += upper_bound(a.begin()+lo,a.begin()+mid,t)-lower_bound(a.begin()+lo,a.begin()+mid,s);
    }
    //sort
    const long long N=a.size();
    long long aid[N];
    for(long long i=lo;i<hi;i++){
        aid[i]=a[i];
    }
    long long k=lo,p=lo,q=mid;
    while(k<hi){
        if(q==hi){
            a[k++]=aid[p++];
        }else if(p==mid){
            a[k++]=aid[q++];
        }else if(aid[p]<aid[q]){
            a[k++]=aid[p++];
        }else{
            a[k++]=aid[q++];
        }
    }
    return res;

}

long long sortandget(vector<long long>&a,long long lo,long long hi,long long L,long long R){
    if(lo==hi)return 0;
    else if(lo+1==hi) {
            if(a[lo]<=R&&a[lo]>=L)return 1;
            else return 0;
    }else{

        long long mid=lo+(hi-lo)/2;
        long long first = sortandget(a,lo,mid,L,R);
        long long sec = sortandget(a,mid,hi,L,R);
        long long third = mergerandget(a,lo,mid,hi,L,R);
        return first+sec+third;
     }

}


class Solution {
public:
    int countRangeSum(vector<int>& v, int L, int R) {
        if(v.size()==0)return 0;
        long long n=v.size();
        vector<long long> sum(n);
        //vä¿å­åiä¸ªæ°çå
        sum[0]=v[0];
        for(long long i=1;i<n;i++){
            sum[i]=sum[i-1]+v[i];
        }
        return sortandget(sum,0,n,L,R);//åé­åå¼åºé´
    }
};