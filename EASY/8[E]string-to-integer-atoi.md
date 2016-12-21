[原题](https://leetcode.com/problems/string-to-integer-atoi/)

题意：

string转化成int。

此题坑多，Easy模式下，通过率最低。

总结其如下：

- 两端的空格要去掉。
- 最前面前面可能会有正负号。
- 最后面可能有非数字，不考虑。
- 其他位置可能有非数字，无效，return 0
- 解析后数据范围要在int范围之内。
- 注意空串的情况。



合适的时候，可以巧妙的使用python的异常。

```
class Solution(object):
    def myAtoi(self, s):
        """
        :type str: str
        :rtype: int
        """
        
        INT_MAX, INT_MIN = 2147483647, -2147483648
        s = s.strip(' ')
        if not s: return 0
        
        #left 
        flag = 1
        if s[0] == '+': s, flag = s[1:], 1
        elif s[0] == '-': s, flag = s[1:], -1
        
        #right
        i = 0
        while i < len(s) and s[i].isdigit(): i += 1
        s = s[:i]
        
        try: x = int(s) * flag
        except:return 0
        
        if x<INT_MIN:
            return INT_MIN
        elif x>INT_MAX:
            return INT_MAX
        else:
            return x
        
```

讨论区的比较好的答案。

```
class Solution(object):
    def myAtoi(self, s):
        """
        :type str: str
        :rtype: int
        """
        ###better to do strip before sanity check (although 8ms slower):
        #ls = list(s.strip())
        #if len(ls) == 0 : return 0
        if len(s) == 0 : return 0
        ls = list(s.strip())
        
        sign = -1 if ls[0] == '-' else 1
        if ls[0] in ['-','+'] : del ls[0]
        ret, i = 0, 0
        while i < len(ls) and ls[i].isdigit() :
            ret = ret*10 + ord(ls[i]) - ord('0')
            i += 1
        return max(-2**31, min(sign * ret,2**31-1))
```

str类型不能del，转化成list，最后的范围处理，很巧妙。