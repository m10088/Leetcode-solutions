[原题](https://leetcode.com/problems/generate-parentheses/)

题意：

给定一个数字n，返回n对匹配的括号的所有的情况。
```
dfs(now, l, r)
```

now：当前的状态的字符串是什么，lr，代表左括号和有括号分别还剩余多少个。


回溯法，但是需要注意回溯状态中一定不能有一种情况，就是左括号剩余的个数不能多于右括号剩余的个数。


```
class Solution(object):
    def generateParenthesis(self, n):
        """
        :type n: int
        :rtype: List[str]
        """
        ret = []
        def dfs(now, l, r):
            if l > r: return
            if l == 0 and r == 0:
                ret.append(now)
                return
            if l-1 >=0 :dfs(now+'(', l-1, r)
            if r-1 >=0 :dfs(now+')', l, r-1)
        dfs('', n, n)
        return ret
```