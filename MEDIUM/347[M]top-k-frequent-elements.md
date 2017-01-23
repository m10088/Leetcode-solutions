[原题](https://leetcode.com/problems/top-k-frequent-elements/)

求元素中出现次数最多的k个元素，明显是hash。

```Python
class Solution(object):
    def topKFrequent(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: List[int]
        """
        from collections import Counter
        counter = collections.Counter(nums)
        
        counter = sorted(counter.iteritems(), key=lambda x: x[1], reverse=True)[:k]
        
        return [val[0] for val in counter]
```

discuss上的个一个网友答案更简洁。

```
return zip(*collections.Counter(nums).most_common(k))[0]
```