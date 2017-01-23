[原题](https://leetcode.com/problems/bitwise-and-of-numbers-range/)


题意：


给定一个区间，判断这个区间内部的数字全部相与之后最后的和是多少。

当然不能暴力解决。


这个是一种解法。


也就是看第i位数字，如果m和n第i位数字，都是1，那么才可能是这一位的最后结果是1,但是也不一定。

因为有可能是从1，变成了0，然后又变成了1。

如何避免这种情况。

就是使用的这条语句，本位的最大跨度是多少个数字？
```
(1 << i)
```

在这总情况下，看这个大小是不是比gap大，如果大于gap那么就，一定是，
那么中间就没有0，因此是合格的，但是如果比gap小，那么结果就一定是中间出现了0，只要中间出现了0，那么这一位就已经不行了。

```C++
class Solution {
    public:
        int rangeBitwiseAnd(long long m, long long n) {
            long long ret = 0;
            long long gap = n - m;
            if (gap == 0) return m;
            long long bit = 1;
            for (int i = 0; i <= 31; i ++) {
                if (m&(1 << i) && n&(1 << i) && (m + (1 << i) - 1>=n)) {
                    ret |= bit;
                }
                bit <<= 1;
            }
            return ret;
        }
}
```

这是第二种方法：


```Python
class Solution(object):
    def rangeBitwiseAnd(self, m, n):
        """
        :type m: int
        :type n: int
        :rtype: int
        """
        movefactor = 1
        while m != n:
            m = m >> 1
            n = n >> 1
            movefactor = movefactor << 1
        return m * movefactor
```

评论区发现的一种高效的解决方法。

解析：

因为如果两个数字不相同的话，那么最低位一定是0；

因为一个是奇数，一个是偶数。

但是两个数字相同的话，就返回那个数字。

每次移位之后，也就是将最后的结果扩大了两倍。


当然也可以给出递归的解决方案。

```C++
int rangeBitwiseAnd(int m, int n) {
    return (n > m) ? (rangeBitwiseAnd(m/2, n/2) << 1) : m;
}
```

