[原题](https://leetcode.com/problems/frog-jump)

题意

题解

```
class Solution(object):
    def canCross(self, stones):
        """
        :type stones: List[int]
        :rtype: bool
        """
        if stones[1] != 1: return False
        target = stones[-1]
        stones = set(stones)
        dp = dict()
        cur = 1
        step = 1
        
        
        def dfs(step, cur):
            if (step,cur) in dp: return dp[(step,cur)]
            if cur==target:
                return True
            nextSteps = [step-1, step, step+1]
            ok = False
            for nextStep in nextSteps:
                if nextStep > 0:
                    if cur + nextStep in stones:
                        if dfs(nextStep, cur+nextStep):
                            ok = True
                            break
            dp[(step, cur)] = ok
            return ok
        
        ret = dfs(step, cur)
        return ret
        
              
                        
```