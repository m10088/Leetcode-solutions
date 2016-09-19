

bool In_set(set<long long>& st, long long low, long long high) {
    if (st.size()==0) return false;
    auto p = st.lower_bound(low);
    if (p == st.end()) return false;


    int tar = *p;
    cout << tar << endl;
    if (low <= tar && tar <= high) return true;
    else return false;
}

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& a, long long k, long long t) {
        if(k<=0 || t<0) return false;

        set<long long> st;
        for (long long i=0; i<a.size(); i++) {
            long long tarl = a[i] - t, tarh = a[i] + t;
            //å¨stä¸­æ¯ä¸æ¯å­å¨ä¸ä¸ªæ°å¤äºtar <= x <= tarh ä¹é´
            if (In_set(st, tarl, tarh)) return true;

            
            //å¤æ­åé¢çä¸ä¸ªæ°æ¯ä¸æ¯éè¦å é¤æ
            if (i<k)
                st.insert(a[i]);
            else {
                st.erase(a[i-k]);
                st.insert(a[i]);
            }
        }
        return false;
        
        
    }
    
};