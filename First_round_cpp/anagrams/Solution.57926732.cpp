class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        if (strs.empty())
            return vector<vector<string> >();

        int len = strs.size();

        //å°å­ç¬¦ä¸²æ°ç»æç§å­å¸é¡ºåºæåº
        sort(strs.begin(), strs.end());

        //å­å¨ç»æ
        vector<vector<string> > ret;

        //å©ç¨åå¸ææ³æå»ºmapï¼å°æåºåç¸ç­çå­ç¬¦ä¸²å­å¨ç¸åºçvector
        map<string, vector<string>> mv;

        for (int i = 0; i < len; i++)
        {
            string str = strs[i];
            sort(str.begin(), str.end());

            mv[str].push_back(strs[i]);
        }

        for (map<string, vector<string> >::iterator iter = mv.begin(); iter != mv.end(); iter++)
            ret.push_back(iter->second);

        return ret;
    }
};