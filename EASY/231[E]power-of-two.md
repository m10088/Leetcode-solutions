[原题](https://leetcode.com/problems/power-of-two/)

题意：

判断一个数字是不是二的幂。

典型的位运算。

```C++
class Solution {
public:
    bool isPowerOfTwo(int n) {
        return n > 0 && !(n&(n-1));
    }
};
```

可是要用python怎做呢？求log然后看是不是整数。

```Python
class Solution(object):
    def isPowerOfTwo(self, n):
        """
        :type n: int
        :rtype: bool
        """
        return False if n <= 0 else (math.log10(n) / math.log10(2)).is_integer()

```