[原题](https://leetcode.com/problems/4sum/)


题意：


和3-sum类似，同时要考虑如何去掉重复。

这里直接采用hash方法解决。

```
class Solution(object):
    def fourSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[List[int]]
        """
        n = len(nums)
        if n < 4: return []
        mp, res = dict(), set()
        for i in range(n):
            for j in range(i+1, n):
                s = nums[i] + nums[j]
                if s not in mp: mp[s] = [[i, j]]
                else: mp[s].append([i, j])
        
        for i in range(n):
            for j in range(i+1, n):
                tmp = nums[i] + nums[j]
                find = target - tmp
                if find not in mp: continue
                for ind in mp[find]:
                    if ind[0] == i or ind[0] == j or \
                        ind[1] == i or ind[1] == j: continue
                    res.add(tuple(sorted([nums[i], nums[j], nums[ind[0]], nums[ind[1]]])))
        return list(res)
                
```

评论区的大牛指出。这道题目的算法复杂度是不可能小于O（n^3）的。



```
Some people say their solutions are O(n2 log n) or even O(n2), but...

Consider cases where nums is the n numbers from 1 to n.
=> There are Θ(n4) different quadruplets (nC4, to be exact, so about n4 / 24).
=> There are Θ(n) possible sums (from 1+2+3+4 to (n-3)+(n-2)+(n-1)+n, so about 4n sums).
=> At least one sum must have Ω(n3) different quadruplets.
=> For that sum, we must generate those Ω(n3) quadruplets.
=> For these cases we have to do Ω(n3) work.
=> O(n2 log n) or even O(n2) are impossible.

(I have seen some previous talk about this, but only in a few answers/comments and I found it lacking. So I thought there should be a question directly stating and proving it.)
```


其实这里也是很坑的，就算你使用了hash，但是你不能保证每个hash的链的长度，因为，有可能hash链的长度，都很长....


所以在最坏的情况下，就算使用了hash，仍然是n^3的复杂度的。

