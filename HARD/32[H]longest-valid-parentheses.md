[原题](https://leetcode.com/problems/longest-valid-parentheses)

题意

题解

```
class Solution(object):
    def longestValidParentheses(self, s):
        """
        :type s: str
        :rtype: int
        """
        if not s: return 0
        stack = []
        matched = [False] * (len(s) + 1) # 用于记录是不是已经被匹配了
        for i in range(len(s)):
            if s[i] == '(':
                stack.append(i)
            else:
                if stack:
                    matched[stack[-1]] = True
                    matched[i] = True
                    stack.pop(-1)
        ret, cur = 0, 0
        for i in range(len(s)):
            if matched[i]:
                cur += 1
            else:
                ret = max(ret, cur)
                cur = 0
        return max(ret, cur)
        
                

```