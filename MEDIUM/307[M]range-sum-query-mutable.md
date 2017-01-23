[原题](https://leetcode.com/problems/range-sum-query-mutable/)

题意：

区间和的动态修改和查询。

水题，但是评论区确实是长见识了。

python还需要好好学。


```Python
class NumArray(object):
    def __init__(self, nums):
        self.update = nums.__setitem__
        self.sumRange = lambda i, j: sum(nums[i:j+1])
```


当然了这道题目如果想，运行的效率都达到log级别的，应当使用线段树or树狀数组。

树狀数组可以参考ACM_solution_repo。


或者[这里。](https://discuss.leetcode.com/topic/31599/java-using-binary-indexed-tree-with-clear-explanation)
