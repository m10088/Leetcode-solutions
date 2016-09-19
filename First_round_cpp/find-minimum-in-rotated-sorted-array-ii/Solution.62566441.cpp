//æåµæ¯è¾å¤æ
int dfs(vector<int>&a,int lo,int hi){//å¨æ¯[]åºé´
    if(a[lo]<a[hi])return lo;
    if(lo==hi)return lo;
    int mid=lo+(hi-lo)/2;
    
    if(a[mid]<a[lo]){//å¦æä¸­é´çæ°æ¯ç¬¬ä¸ä¸ªæ°å°ï¼é£ä¹å­å¨äºåé¢çåºé´
        return dfs(a,lo,mid);
    }else if(a[mid]>a[lo]){//å¦æä¸­é´çæ°æ¯ç¬¬ä¸ä¸ªæ°å¤§ï¼é£ä¹å­å¨äºåé¢çåºé´
        return dfs(a,mid+1,hi);
    }else{
        //å¦ææ¯æåä¸ä¸ªåç´ å¤§ï¼é£ä¹å­å¨äºåé¢çåºé´
        if(a[mid]>a[hi])return dfs(a,mid+1,hi);
        //else return std::min(dfs(a,lo,mid),dfs(a,mid+1,hi));
        else{
            int fir=dfs(a,lo,mid);
            int sec=dfs(a,mid+1,hi);
            if(a[fir]<a[sec])return fir;
            else return sec;
        }
    }
}

class Solution {
public:
    int findMin(vector<int>& nums) {
        //åå¤æ­æ¯ä¸æ¯åè°çå¦ææ¯åè°çï¼å°±ä¸ç¨éå½ï¼ç´æ¥è¾åº
        return nums[dfs(nums,0,nums.size()-1)];
    }
};