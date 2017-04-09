[原题](https://leetcode.com/problems/basic-calculator)

题意

题解

```
class Solution(object):
    def calculate(self, s):
        """
        :type s: str
        :rtype: int
        """
        stack, objs = '', []
        for char in s:
            # print char
            if char == ' ': continue
            if char not in '0123456789':
                if stack:
                    objs.append(int(stack))
                    stack = ''
                objs.append(char)
            else:
                stack += char
        if stack:
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
            elif obj in '*/': # 如果遇到乘除法，那么只能进行前面的乘除法，遇到+-或者括号都要停止
                while len(operator_stack) != 0 and operator_stack[-1] in '*/':
                    _apply(operator_stack.pop())
                operator_stack.append(obj)
            elif obj in '+-':  # 如果遇到加减法，那么能进行前面的+-/*，遇到左括号停止
                while len(operator_stack) != 0 and operator_stack[-1] != '(':
                    _apply(operator_stack.pop())
                operator_stack.append(obj)
            elif obj == '(':
                operator_stack.append(obj)
            else: # 遇到右括号，将左括号之间的全部进行运算
                while len(operator_stack) != 0 and operator_stack[-1] != '(':
                    _apply(operator_stack.pop())
                operator_stack.pop(-1)
                
                
                
        while len(operator_stack) != 0: # 将栈中剩余的全部计算完
                _apply(operator_stack.pop())
        return ret_stack[0]
        
        
        
```