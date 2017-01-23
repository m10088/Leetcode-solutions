[原题](https://leetcode.com/problems/basic-calculator-ii/)

题意：

计算器模拟：只有加减乘除。

比如

```
"3+2*2" = 7
" 3/2 " = 1
" 3+5 / 2 " = 5
```

其实不用单独转化成逆波兰式，只要在转化的同时，计算出结果就行了。

规定：

如果遇见了乘除，那么将栈中下一个乘除前面的所有的加减全部弹出并应用。
如果遇到了加减，那么将栈中的运算符，全部弹出并应用。


```Python
class Solution(object):
    def calculate(self, s):
        """
        :type s: str
        :rtype: int
        """
        stack, objs = '', []
        for char in s:
            if char == ' ': continue
            if char in '+-*/':
                objs.append(int(stack))
                stack = ''
                objs.append(char)
            else:
                stack += char
        objs.append(int(stack))
        
        # get_answer
        operator_stack = []
        ret_stack = []
        
        def _apply(char):
            op2 = ret_stack.pop()
            op1 = ret_stack.pop()
            if char == '+':
                ret_stack.append(op1 + op2)
            elif char == '-':
                ret_stack.append(op1 - op2)
            elif char == '*':
                ret_stack.append(op1 * op2)
            else:
                ret_stack.append(op1 / op2)
        
        for obj in objs:
            if isinstance(obj, int):
                ret_stack.append(obj)
            elif obj in '*/':
                while len(operator_stack) != 0 and operator_stack[-1] in '*/':
                    _apply(operator_stack.pop())
                operator_stack.append(obj)
            else:
                while len(operator_stack) != 0:
                    _apply(operator_stack.pop())
                operator_stack.append(obj)
        while len(operator_stack) != 0:
                _apply(operator_stack.pop())
        return ret_stack[0]
        
        
        
```