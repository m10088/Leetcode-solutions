[原题](https://leetcode.com/problems/is-subsequence/)

题意：

给定一个s（很短）和一个t（很长），看s是不是t的字串，也就是将t删除一部分能不能得到s。

我的思路：

26个字母作为键，position的链表作为值进行hash。

然后对s中的每个字母在hash表中查找，因为hash表中的每个链表都是有序的，因此可以使用类似lowerbound进行查找，如果最后能顺利，进行，那么返回true，否则返回false。

```
class Solution(object):
    def isSubsequence(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: bool
        """
        # not the lower bound 
        def lower_bound(lo, hi, target, nums):
            res = None
            while lo < hi:
                mid = (lo + hi) // 2
                if nums[mid] <= target: # attention here, I modify the lower_bound_fuction.
                    lo = mid + 1
                    res = lo
                else:
                    hi = mid
                    res = hi
            return res
        
        positions = dict()
        for i, char in enumerate(t):
            if char not in positions:
                positions[char] = [i]
            else:
                positions[char].append(i)
        for key, value in positions.items():
            positions[key] = sorted(value)
        
        begin = -1
        for char in s:
            if char not in positions: return False
            nums = positions[char]
            n = len(nums)
            index = lower_bound(0, n, begin, nums)
            if index == n: return False
            begin = nums[index]
            print begin
        return True
            
        
```

如果不考虑题目“t是固定的很长的字符串，s是很短的字符串”，那么显然，t是可以每次测试的时候都进行遍历的。

```
bool isSubsequence(char* s, char* t) {
    while (*t)
        s += *s == *t++;
    return !*s;
}
```