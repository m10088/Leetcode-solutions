[原题](https://leetcode.com/problems/verify-preorder-serialization-of-a-binary-tree)

题意:

看按照一个序列能不能构成一个二叉树。

当然可以定义一种结构，手动进行建树。但是其实能发现更明显的结构，就是结尾的两个 ``` # ``` 能够将前面的一个node带提成一个``` # ```，当然为了减少错误处理，使用try语句很方便。


题解:

```Python
class Solution(object):
    def isValidSerialization(self, preorder):
        """
        :type preorder: str
        :rtype: bool
        """
        stack = []
        pre = preorder.split(',')
        
        for item in pre:
            stack.append(item)
            try:
                while stack[-1] == '#' and stack[-2] == '#' and stack[-3] != '#':
                    stack.pop(-1)
                    stack.pop(-1)
                    stack[-1] = '#'
            except:
                pass
        return stack == ['#']
```