[原题](https://leetcode.com/problems/utf-8-validationy)

题意:

阅读理解题，判断一个数组能不能构成utf-8解码序列。


题解:

```
class Solution(object):
    def validUtf8(self, data):
        """
        :type data: List[int]
        :rtype: bool
        """
        def getbin(data):
            # {:*^20s}----'.format('welcome')
            return '{:0<^8s}'.format(bin(data)[2:])
        counter = 0
        print getbin(1)
        
        for num in data:
            print getbin(num)
            if counter == 0:
                if getbin(num).startswith('110'): counter = 1
                elif getbin(num).startswith('1110'): counter = 2
                elif getbin(num).startswith('11110'): counter = 3
                elif getbin(num).startswith('1'): return False
            else:
                if not getbin(num).startswith('10'): return False
                counter -= 1
        return counter == 0
```

