[原题](https://leetcode.com/problems/different-ways-to-add-parentheses)

题意:

给定一个字符串的算式，分别给予不同的优先级。返回所有可能的结果。

题解:


首先将这个序列处理出来，然后对(i, j)使用记忆化搜索即可。

对于每个(i, j)状态，返回一个list序列，将两个list按照某种运算求类似笛卡尔乘积。

```

class Solution(object):
    
    def get_list(self, s):
        nums, tmp = [], ''
        for char in s:
            if char in '+-*':
                nums.append(tmp)
                nums.append(char)
                tmp = ''
            else:
                tmp += char
        nums.append(tmp)
        return nums
    
    def diffWaysToCompute(self, s):
        """
        :type input: str
        :rtype: List[int]
        """
        nums = self.get_list(s)
        cache = dict()
        def cross(x, y, fx):
            return [fx(m, n) for m in x for n in y]
        
        def aid(l, r): # [l, r]区间内能够组成的list有哪些
            if (l, r) in cache: 
                return cache[(l, r)]
            if l == r:
                cache[(l, r)] = [int(nums[l])]
                return [int(nums[l])]
            else:
                ret = []
                for split in range(l+1, r, 2):
                    left, right = aid(l, split-1), aid(split+1, r)
                    if nums[split] == '*':
                        ret = ret + cross(left, right, lambda x, y: x * y)[:]
                    elif nums[split] == '-':
                        ret = ret + cross(left, right, lambda x, y: x - y)[:]
                    else:
                        ret = ret + cross(left, right, lambda x, y: x + y)[:]
                cache[(l, r)] = ret
                return ret
        
        return aid(0, len(nums)-1)
```
