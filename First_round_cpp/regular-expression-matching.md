```c++
class Solution(object):
    def isMatch(self, s, p):
        """
        :type s: str
        :type p: str
        :rtype: bool
        """
        return re.match(r'^'+p+r'$',s) != None
    
        
           
```
