class Solution(object):
    cache = {}
    def __init__(self):
        self.cache.clear()
    def wordBreak(self, s, d):
        """
        :type s: str
        :type wordDict: Set[str]
        :rtype: bool
        """
        #éå½çå¤æ­,å¦æåé¢çå·²ç»æäº,ä½æ¯æå¤ªå¤çéå¤è®¡ç®,å¯ä»¥ä½¿ç¨è®°å¿åæ¹æ³
        if s in self.cache:
            return self.cache[s]
        if s in d:
            self.cache[s] = True
            return True
        half = (len(s))
        k = 0
        while k <= half:
            i = half + k
            j = half - k
            if i==0 or i==len(s):
                pass
            else:
                if self.wordBreak(s[:i],d) == True and self.wordBreak(s[i:],d) == True:
                    self.cache[s] = True
                    return True
                    
            if j==0 or j==len(s):
                pass
            else:
                if self.wordBreak(s[:j],d) == True and self.wordBreak(s[j:],d) == True:
                    self.cache[s] = True
                    return True
                    
            k += 1
            
        self.cache[s] = False    
        return False