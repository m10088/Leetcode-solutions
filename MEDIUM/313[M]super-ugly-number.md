[原题](https://leetcode.com/problems/super-ugly-number/)


题意：

丑数的升级版，仍然是求第n个丑数，但是不再是2，3，5是指定的数字。


其实难点就是防止出现重复的情况，我们巧妙的使用一个数组指针解决，每当添加一个数字到丑数的集合中，就遍历一次这些指针，适当的推进一步，防止下一次重复的添加进去。

```Python
class Solution(object):
    def nthSuperUglyNumber(self, target, primes):
        """
        :type n: int
        :type primes: List[int]
        :rtype: int
        """
        res = [1]
        if target == 1: return res[0]
        n = len(primes)
        cur = [0] * n
        # 除去第一个实际上是找target-1个
        for i in range(1, target):
            miner = float('inf')
            for k in range(n):
                miner = min(miner, primes[k] * res[cur[k]])
            res.append(miner)
            for k in range(n):
                if res[-1] % primes[k] == 0:
                    cur[k]+= 1
        
        return res[-1]
        
```