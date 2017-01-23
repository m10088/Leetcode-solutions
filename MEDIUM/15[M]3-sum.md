[原题](https://discuss.leetcode.com/category/23/3sum)


题意：

给定一个target数字，找数组中所有的能够凑成target的组合，因为最后的结果是用值表示的，不是index因此可能出现重复，因此需要去掉重复。

因为之前的two-sum可以hash，排序后双指针，因此，这里是相同的道理。


可以进行双指针，就是每当固定一个数字，就对剩余的后面的数字使用双指针。如果对特殊情况进行处理，还可以即时的去掉重复，不用使用set去重或者最后去重。


```java

public List<List<Integer>> threeSum(int[] num) {
    Arrays.sort(num);
    List<List<Integer>> res = new LinkedList<>(); 
    for (int i = 0; i < num.length-2; i++) {
        if (i == 0 || (i > 0 && num[i] != num[i-1])) {
            int lo = i+1, hi = num.length-1, sum = 0 - num[i];
            while (lo < hi) {
                if (num[lo] + num[hi] == sum) {
                    res.add(Arrays.asList(num[i], num[lo], num[hi]));
                    while (lo < hi && num[lo] == num[lo+1]) lo++;
                    while (lo < hi && num[hi] == num[hi-1]) hi--;
                    lo++; hi--;
                } else if (num[lo] + num[hi] < sum) lo++;
                else hi--;
           }
        }
    }
    return res;
}

```

hash的方法。

```Python
class Solution(object):
    def threeSum(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        if len(nums) < 3 : return []
        
        mp = dict()
        n = len(nums)
        res = set()
        nums = sorted(nums)
        
        for i in range(1, n):
            # find any result in the hashtable
            target = -nums[i]
            if target in mp:
                for tuple_ in mp[target]:
                    if i in tuple_: continue
                    res.add(tuple(sorted([nums[tuple_[0]], nums[tuple_[1]], nums[i]])))
            
            for j in range(0, i):
                if j > 0 and nums[j] == nums[j-1]: continue
                # put it in the table
                s = nums[i] + nums[j]
                if s not in mp:
                    mp[s] = [(i, j)]
                else:
                    mp[s].append((i, j))
        return list(res)
        
            
                
                    
```