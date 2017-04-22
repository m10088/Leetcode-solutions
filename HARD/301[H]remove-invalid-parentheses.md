[原题](https://leetcode.com/problems/remove-invalid-parentheses)

题意

题解

```Python
class Solution(object):
    def removeInvalidParentheses(self, s):
        """
        :type s: str
        :rtype: List[str]
        """
        # BFS即可
        def isvalid(t):
            counter = 0
            for char in t:
                if char==')':
                    counter = counter - 1
                elif char == '(':
                    counter = counter + 1
                if counter < 0: return False
            return counter == 0
        
        q, ret, found = [s], set(), False
        visited = set() # 优化-防止TLE
        while len(q):
            fro = q.pop(0)
            if isvalid(fro):
                ret.add(fro)
                found = True
            if found: continue
            for i in range(len(fro)):
                # 替换每个字母进入队列
                if fro[i] in '()':
                    tmp = fro[:i] + fro[i+1:]
                    if tmp not in visited:
                        q.append(tmp)
                        visited.add(tmp)
        return list(ret)
        
        
            
        
```