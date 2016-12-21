[原题](https://leetcode.com/problems/count-primes/)


题意：

统计小于n的素数的个数：

如果使用naive的判断方法的话，每个数字检查需要O(sqrt(n))的复杂度。

尝试埃氏筛选方法，但是超内存了，
```
class Solution(object):
    def countPrimes(self, n):
        """
        :type n: int
        :rtype: int
        """
        if n < 2:return 0
        is_prime = [1] * n
        is_prime[0] = is_prime[1] = 0
        
        for i in range(2, n):
            if is_prime[i] == 1:
                for j in range(i * i, n, i):
                    is_prime[j] = 0
        
        return sum(is_prime)
```

最后使用了一个优化AC

```
for i in range(2, int(math.ceil(math.sqrt(n)))):
```

但是按理说，这个应该是TLE才对啊。
