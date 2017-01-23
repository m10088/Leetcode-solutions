[原题](https://leetcode.com/problems/restore-ip-addresses/)


题意：

给定一串数字，返回所有可能的ip地址的情况。


分析：

回溯dfs即可。

需要注意的特殊情况有：

数组的长度大于12那么一定是不可能的。

如果数字的位数大于1，并且以0开头，那么这种情况我们直接不考虑。

为了简单，简单返回所有可能的情况，对其进行进一步过滤。

```Python
class Solution(object):
    def restoreIpAddresses(self, s):
        """
        :type s: str
        :rtype: List[str]
        """
        n = len(s)
        if n > 12: return [] # this is important
        tmp = [0] * n
        ret = []
        def dfs(cur, k):
            if cur == n and k == 4:
                ret.append(tmp[0:4])
                return
            for i in range(1, 4):
                _next = cur + i
                if _next <= n:
                    # specail case '0', attention!
                    if i > 1 and s[cur] == '0': continue
                    tmp[k] = int(s[cur:_next])
                    dfs(_next, k+1)
        dfs(0, 0)
        res = []
        for item in ret:
            valid = True
            for num in item:
                if not 0 <= num < 256: valid = False
            if valid: res.append([str(x) for x in item])
        return ['.'.join(x) for x in res]
            
            
```

评论区的一种暴力的解法，很不错。


```C++
// c++  code
    vector<string> restoreIpAddresses(string s) {
        vector<string> ret;
        string ans;
        
        for (int a=1; a<=3; a++)
        for (int b=1; b<=3; b++)
        for (int c=1; c<=3; c++)
        for (int d=1; d<=3; d++)
            if (a+b+c+d == s.length()) {
                int A = stoi(s.substr(0, a));
                int B = stoi(s.substr(a, b));
                int C = stoi(s.substr(a+b, c));
                int D = stoi(s.substr(a+b+c, d));
                if (A<=255 && B<=255 && C<=255 && D<=255)
                    if ( (ans=to_string(A)+"."+to_string(B)+"."+to_string(C)+"."+to_string(D)).length() == s.length()+3)
                        ret.push_back(ans);
            }    
        
        return ret;
    }
```