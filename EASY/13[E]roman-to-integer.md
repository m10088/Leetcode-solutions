[原题](https://leetcode.com/problems/roman-to-integer/)

题意：

罗马数字转化成数字。

正则表达式的解法：

```C++
r'''^

(M{0,3})
(CM|CD|D?C{0,3})
(XC|XL|L?X{0,3})
(IX|IV|V?I{0,3})

$'''
```

然后分别检测每一组数字的大小。

```Python

import re
class Solution(object):
    def romanToInt(self, s):
        """
        :type s: str
        :rtype: int
        """
        m = re.match(r'''^(M{0,3})(CM|CD|D?C{0,3})(XC|XL|L?X{0,3})(IX|IV|V?I{0,3})$''', s)
        fir = m.group(1)
        sec = m.group(2)
        thr = m.group(3)
        fot = m.group(4)
        
        res = len(fir)*1000
        
        if len(sec) != 0:
            if sec.find('M') != -1:
                res += 900
            elif sec.find('D') == -1:
                res += 100 * len(sec)
            else:
                if sec[0] == 'D':
                    res += len(sec[1:])*100 + 500
                else:
                    res += 400
        
        if len(thr) != 0:
            if thr.find('C') != -1:
                res += 90
            elif thr.find('L') == -1:
                res += 10 * len(thr)
            else:
                if thr[0] == 'L':
                    res += len(thr[1:])*10 + 50
                else:
                    res += 40
        
        
        if len(fot) != 0:
            if fot.find('X') != -1:
                res += 9
            elif fot.find('V') == -1:
                res += 1 * len(fot)
            else:
                if fot[0] == 'V':
                    res += len(fot[1:])*1 + 5
                else:
                    res += 4
                    
        return res
        
        
```


又是讨论区的精彩解法。

因为每一组实际上是独立的。
主要的问题就是类似VII和IV如何区别的问题。

从后面开始扫描。

实际上只要判断一个字符比它前面的字符大还是小就行。


```Python
def romanToInt(self, s):

        romans = {'M': 1000, 'D': 500 , 'C': 100, 'L': 50, 'X': 10,'V': 5,'I': 1}

        prev_value = running_total =0
        
        for i in range(len(s)-1, -1, -1):
            int_val = romans[s[i]]
            if int_val < prev_value:
                running_total -= int_val
            else:
                running_total += int_val
            prev_value = int_val
        
        return running_total
```