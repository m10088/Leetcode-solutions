[原题](https://leetcode.com/problems/permutations/)

题意：

求全排列的所有情况。

C++当然直接调用函数就行了。

如果用python，我们实际上，是可以自己实现下的。

```Python
class Solution(object):
    def permute(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        ret = []
        n = len(nums)
        def recursively(tmpRes, begin, n):
            if begin == n:
                ret.append(tmpRes[:])
                return
            # the 0~begin-1 has been fixed
            recursively(tmpRes, begin+1, n)
            for i in range(0, begin):
                tmpRes[i], tmpRes[begin] = tmpRes[begin], tmpRes[i]
                recursively(tmpRes, begin+1, n)
                tmpRes[i], tmpRes[begin] = tmpRes[begin], tmpRes[i]
        recursively(nums, 1, n)
        return ret

```

另外一种速度比较快的，使用的python的生成器的解法。

```Python
class Solution(object):
    
    def permute(self, nums):

        def permutations(nums):
            if not nums:
                yield []
            for n in nums:
                for permut in permutations([i for i in nums if i != n]):
                    yield [n] + permut
                    
        return [permut for permut in permutations(nums)]
```
