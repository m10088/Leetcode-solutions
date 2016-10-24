```c++
class Solution(object):
    cache = {}
    def dfs(self,s1,s2,s3,i,j,k):#å¿é¡»ä¿è¯ä¼ å¥çi,j,k >= 0
        if (i,j,k) in self.cache:
            return self.cache[(i,j,k)]
        
        if i == 0 and j ==0 and k ==0:
            self.cache[(i,j,k)] = True
            return True
        
        if i == 0:
            if s2[:j] == s3[:k]:
                self.cache[(i,j,k)] = True
                return True
            else:
                self.cache[(i,j,k)] = False
                return False
        if j == 0:
            if s1[:i] == s3[:k]:
                self.cache[(i,j,k)] = True
                return True
            else:
                self.cache[(i,j,k)] = False
                return False
        else:
            
            if s3[k-1] != s2[j-1] and s3[k-1] != s1[i-1]:
                self.cache[(i,j,k)] = False
                return False
            elif s3[k-1] == s2[j-1] and s3[k-1] != s1[i-1]:
                self.cache[(i,j,k)] = self.dfs(s1,s2,s3,i,j-1,k-1)
                return self.cache[(i,j,k)]
            elif s3[k-1] != s2[j-1] and s3[k-1] == s1[i-1]:
                self.cache[(i,j,k)] = self.dfs(s1,s2,s3,i-1,j,k-1)
                return self.cache[(i,j,k)]
            else:
                self.cache[(i,j,k)] = self.dfs(s1,s2,s3,i-1,j,k-1) or self.dfs(s1,s2,s3,i,j-1,k-1)
                return self.cache[(i,j,k)]
        
    def isInterleave(self, s1, s2, s3):
        """
        :type s1: str
        :type s2: str
        :type s3: str
        :rtype: bool
        """
        self.cache.clear()
        if len(s1)+len(s2) != len(s3):
            return False
        return self.dfs(s1,s2,s3,len(s1),len(s2),len(s3))
```
