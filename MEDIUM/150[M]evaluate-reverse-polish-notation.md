[原题](https://leetcode.com/problems/evaluate-reverse-polish-notation/)

题意：

对逆波兰表达式求值。

注意的点，python的负数除法和其他的语言不太一样，

```Python
class Solution(object):
    def evalRPN(self, tokens):
        stack = []
        for t in tokens:
            if t not in ["+", "-", "*", "/"]:
                stack.append(int(t))
            else:
                r, l = stack.pop(), stack.pop()
                if t == "+":
                    stack.append(l+r)
                elif t == "-":
                    stack.append(l-r)
                elif t == "*":
                    stack.append(l*r)
                else:
                    # here take care of the case like "4/-3",
                    # in Python 2.x, it returns -2, while in 
                    # Leetcode it should return -1
                    if l*r < 0 and l % r != 0:
                        stack.append(l//r+1)
                    else:
                        stack.append(l//r)
        return stack.pop()
```