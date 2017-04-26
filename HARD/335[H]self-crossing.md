[原题](https://leetcode.com/problems/self-crossing)

题意

题解

```Python
# 参考 http://www.cnblogs.com/grandyang/p/5216856.html
class Solution(object):
    def isSelfCrossing(self, x):
        """
        :type x: List[int]
        :rtype: bool
        """
  
   
        for i in range(3, len(x)):
            if x[i] >= x[i - 2] and x[i - 3] >= x[i - 1]: 
                return True;
            
            if i >= 4 and x[i-1] == x[i-3] and x[i] >= x[i-2] - x[i-4]:
                return True;
            
            if i >= 5 and x[i-2] >= x[i-4] and x[i-3] >= x[i-1] and x[i-1] >= x[i-3] - x[i-5] and x[i] >= x[i-2] - x[i-4]:
                return True;
            
        
        return False;
    

```