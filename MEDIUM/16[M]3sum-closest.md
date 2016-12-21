[原题](https://leetcode.com/problems/3sum-closest/)


题意：

给定一个数组，找三个不同位置的数字，让这三个数字的和离target最近，结果最近的假设只有一个。


这个题目，明显不能够使用hash，因此考虑排序+双指针，但是要考虑双指针移动的条件。

```
class Solution(object):
    def threeSumClosest(self, num, target):
        num.sort()
        result = num[0] + num[1] + num[2]
        for i in range(len(num) - 2):
            j, k = i+1, len(num) - 1
            while j < k:
                sum_ = num[i] + num[j] + num[k]
                if sum_ == target:
                    return sum_
                
                if abs(sum_ - target) < abs(result - target):
                    result = sum_
                
                if sum_ < target:
                    j += 1
                elif sum_ > target:
                    k -= 1
        return result
        
```

其实想了一下，也可以，预处理出两个不同位置的数字的和，然后排序，枚举第三个数字的时候，使用二分查找，但是需要考虑的情况比较多。首先一点就是第三个数字的索引，不能够和前两个中的任何一个相同。然后就是二分查找target-tmpsum.