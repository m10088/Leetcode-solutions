[原题](https://leetcode.com/problems/expression-add-operators)

题意

题解

```Python
class Solution(object):
    def addOperators(self, num, target):
        """
        :type num: str
        :type target: int
        :rtype: List[str]
        """
        ret = []
        def dfs(num, diff, cur, saved):
            # print num, diff, cur, saved
            if len(num)==0:
                if cur==target: ret.append(saved)
            else:
                for i in range(1, len(num)+1):
                    deltstr = num[:i]
                    delt = int(deltstr)
                    if i>1 and deltstr[0]=='0': continue # 前导0，忽略
                    if saved:
                        dfs(num[i:], delt, cur+delt, saved+'+'+deltstr)
                        dfs(num[i:], -delt, cur-delt, saved+'-'+deltstr)
                        dfs(num[i:], diff*(delt), cur-diff+diff*delt, saved+'*'+deltstr)
                    else:
                        dfs(num[i:], delt, delt, saved+deltstr)
        dfs(num, 0, 0, '')
                        
        return ret
        
```