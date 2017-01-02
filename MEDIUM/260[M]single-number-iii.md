[原题](https://leetcode.com/problems/single-number-iii)

题意:

有两个数字出现了1次，其他的都出现了2次。

题解:

```
class Solution(object):
    def singleNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        xor = reduce(lambda x, y: x^y, nums)
        # xor的最后一位不是0的位置是k
        k = 0
        while not (xor & (1 << k)): k += 1
        first, second = 0, 0
        for num in nums:
            # 那么忽略那些出现次数2次的数字，（因为他们异或两次之后不起任何作用），仅仅通过第k位数字的值，就能把两个数字筛选出来
            if num & (1 << k) == 0: first = first ^ num
            else: second = second ^ num
        return [first, second]
```

