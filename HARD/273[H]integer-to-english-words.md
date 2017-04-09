[原题](https://leetcode.com/problems/integer-to-english-words)

题意

题解

```
class Solution(object):
    def numberToWords(self, num):
        """
        :type num: int
        :rtype: str
        """
        num = int(num)
        if num == 0: return 'Zero'
        a = []
        u = ['' , 'Thousand', 'Million', 'Billion']
        b = ['', 'One', 'Two', 'Three', 'Four', 'Five', 'Six', 'Seven', 'Eight', 'Nine', 'Ten', 'Eleven', 'Twelve', 'Thirteen', 'Fourteen', 'Fifteen', 'Sixteen', 'Seventeen', 'Eighteen', 'Nineteen']
        c = ['', '', 'Twenty', 'Thirty', 'Forty', 'Fifty', 'Sixty', 'Seventy', 'Eighty', 'Ninety']
        
        # 得到1-99之间的数字的英文表示方法
        def getTy(x):
            if x < 20: 
                return [b[x]]
            low, high = x % 10, x // 10
            if low == 0:
                return [c[high]]
            else:
                return [c[high], b[low]]
        
        # 得到 1-999之间的数字英文表示方式
        def getHundred(x):
            if x < 100: return getTy(x)
            low, high = x % 100, x // 100
            if low == 0:
                return [b[high], 'Hundred']
            else:
                return [b[high], 'Hundred'] + getTy(low)
            
        while num:
            a.append(num % 1000)
            num = num // 1000
        ret = []
        for i in range(len(a)-1, -1, -1):
            if a[i] == 0: continue
            ret += getHundred(a[i])
            ret += [u[i]]
        
        return ' '.join(ret).strip()
                
            
        
```