[原题](https://leetcode.com/problems/combination-sum-iv)

题意:

```
nums = [1, 2, 3]
target = 4

The possible combination ways are:
(1, 1, 1, 1)
(1, 1, 2)
(1, 2, 1)
(1, 3)
(2, 1, 1)
(2, 2)
(3, 1)

```

返回的结果是7

题解:

这道题目因为不同返回组合的具体结果，因此使用dp就行。

一开始的时候是```dp[i][j]```，代表从前i个数字，总凑出j一共有多少种方法，但是后来发现，类似(1,1,2)和(2,1,1)在结果中重复出现了，因此是不必考虑顺序的，因此只要统计dp[j]，也就是考虑使用所有的数字凑出j有多少种方式即可。


记忆搜索的的方式。

```
class Solution(object):
    def combinationSum4(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        cache = dict()
        def dfs(target):
            if target == 0: return 1
            if target < 0: return 0
            if target in cache: return cache[target]
            counter = 0
            for num in nums:
                counter += dfs(target-num)
            cache[target] = counter
            return counter
            
        return dfs(target)
```

从下往上也行。

```java
public int combinationSum4(int[] nums, int target) {
    int[] comb = new int[target + 1];
    comb[0] = 1;
    for (int i = 1; i < comb.length; i++) {
        for (int j = 0; j < nums.length; j++) {
            if (i - nums[j] >= 0) {
                comb[i] += comb[i - nums[j]];
            }
        }
    }
    return comb[target];
}
```


