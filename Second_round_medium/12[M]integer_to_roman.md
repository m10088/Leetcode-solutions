[原题](https://leetcode.com/problems/integer-to-roman/)


题意：

将阿拉伯数字转化成罗马数字。

python_code


```

class Solution(object):
    def intToRoman(self, num):
        """
        :type num: int
        :rtype: str
        """

        d = {1000: 'M', 900: 'CM', 500: 'D', 400: 'CD', 100: 'C', 90: 'XC', 50: 'L', 40: 'XL', 10: 'X', 9: 'IX',
             5: 'V', 4: 'IV', 1: 'I'}
        roman = ""

        for v in sorted(d.keys(), reverse=True):
            roman += (num // v) * d[v]
            num -= (num // v) * v

        return roman
```


讨论区的另外一种简洁的方法。


```
public static String intToRoman(int num) {
    String M[] = {"", "M", "MM", "MMM"};
    String C[] = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
    String X[] = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
    String I[] = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
    return M[num/1000] + C[(num%1000)/100] + X[(num%100)/10] + I[num%10];
}
```
