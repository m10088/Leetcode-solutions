[原题](https://leetcode.com/problems/minimum-moves-to-equal-array-elements-ii)

题意:

给定一个数组，每次，只能让其中的一个数字加一或者减一，为了让最后所有的数字全部同，一共需要进行多少次操作。

题解:

这道题目在算法导论上的课后题有，基本思路就是先找到中位数，中位数就是最后全相同的那个值，然后计算其他的数值和中位数的绝对值，然后求和就行。

如果是偶数个数字，那么中位数就要分别尝试中间的两个数字。

求中位数的算法，如果使用算法导论上的算法，算法复杂度是O(n)，一般情况下，O(nlgn)排下序就行了。

```Python
class Solution(object):
    def minMoves2(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        # 首先找到中位数, 然后计算即可
        nums = sorted(nums)
        median, n = [], len(nums)
        if n % 2 == 1:
            median.append(nums[n // 2])
        else:
            median.append(nums[n // 2])
            median.append(nums[n // 2 - 1])
        def get_ans(val, f):
            return sum([f(x) for x in nums])
        return max([get_ans(x, lambda a: abs(a-x)) for x in median])
        
        # 这道题目的另外的一种解法，就是使用select_k的方法找到中位数，这种方式的算法复杂度是O(n)，但是如果是使用排序，算法复杂度是O(nlgn)
        
            
```

