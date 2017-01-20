[原题](https://leetcode.com/problems/integer-replacement)

题意:

一个数字如果是偶数那变成一半，如果是奇数，那么加一或者减一。求最后变成1，最少需要多少步。


题解:


总之偶数很简单，如果是奇数，如何根据数字的特点，确定是+1还是-1。

我们的目的其实就是不断的减少二进制中数字1的数量，所以+1和-1分别比较运算之后的那个结果的二进制中数字1的数量。

当然这里有一个特殊的点，就是3，需要单独处理。

```

class Solution(object):
    def integerReplacement(self, n):
        """
        :type n: int
        :rtype: int
        """
        def countones(n):
            return bin(n).count('1')
        
        
        counter = 0
        while n != 1:
            if n % 2 == 0:
                n = n / 2
            elif n == 3: # this is special case
                n = n - 1
            else:
                n = n - 1 if countones(n-1) < countones(n+1) else n + 1
            
            counter += 1
        return counter
```

评论区进行了进一步分析。

```
Of course, doing bitCount on every iteration is not the best way. It is enough to examine the last two digits to figure out whether incrementing or decrementing will give more 1's. Indeed, if a number ends with 01, then certainly decrementing is the way to go. Otherwise, if it ends with 11, then certainly incrementing is at least as good as decrementing (*011 -> *010 / *100) or even better (if there are three or more 1's). This leads to the following solution:
```

```java
public int integerReplacement(int n) {
    int c = 0;
    while (n != 1) {
        if ((n & 1) == 0) {
            n >>>= 1;
        } else if (n == 3 || ((n >>> 1) & 1) == 0) {
            --n;
        } else {
            ++n;
        }
        ++c;
    }
    return c;
}
```