#define INF 0x7fffffff
class Solution {
public:
    int nthSuperUglyNumber(int tar, vector<int>& primes){
        
        vector<int> res;
        res.push_back(1);
        if(tar==1)return res[0];
        const int n=primes.size();
        int index[n];
        memset(index,0,sizeof(index));
        for(int i=1;i<tar;i++){
            int miner=INF;
            for(int k=0;k<n;k++){
                miner=std::min(miner,primes[k]*res[index[k]]);
            }
            res.push_back(miner);
            for(int i=0;i<n;i++){
                if(res.back()%primes[i]==0){
                    index[i]++;
                }
            }
        }
        return res.back();
    }
};