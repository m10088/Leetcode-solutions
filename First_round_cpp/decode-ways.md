```c++
class Solution(object):
    cache = {}
    def __init__(self):
        self.cache.clear()
    def dfs(self,s):
        
        if s in self.cache:
            return self.cache[s]
        if s=='':
            self.cache[s] = 1
            return 1
        else:
            if s[0] == '0':
                self.cache[s] = 0
                return 0
            else:
                if len(s) == 1:
                    self.cache[s] = self.dfs(s[1:])
                    return self.cache[s]
                else:
                    if int(s[0:2])<=26:
                        self.cache[s] = self.dfs(s[1:]) + self.dfs(s[2:])
                        return self.cache[s]
                    else:
                        self.cache[s] = self.dfs(s[1:])
                        return self.cache[s]
        
        
        
    def numDecodings(self, s):
        """
        :type s: str
        :rtype: int
        """
        if s == '':
            return 0
        else:
            return self.dfs(s)
       
```
