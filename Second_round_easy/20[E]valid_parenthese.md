[原题](https://leetcode.com/problems/valid-parentheses/)

题意：

检查各种括号是不是匹配；

用栈模拟即可。

```
class Solution(object):
    def isValid(self, s):
        """
        :type s: str
        :rtype: bool
        """
        if len(s)%2 is 1:
            return False
        dic={
            "(":")",
            "[":"]",
            "{":"}"
            }
        stack=[]
        for i in s:
            if i == '(' or i == '{' or i == '[':
                stack.append(i)
            else:
                if len(stack) != 0 and dic[stack.pop()] != i:
                    return False
        return len(stack) == 0
```

讨论区竟然玩起了正则表达式。

clean and clever solution.

```
    while True:
        a = s == s.replace("()","")
        s = s.replace("()","")
        b = s == s.replace("{}","")
        s = s.replace("{}","")
        c = s == s.replace("[]","")
        s = s.replace("[]","")
        if a and b and c:
            break
    return s == ""
```

