[原题](https://leetcode.com/problems/contains-duplicate-iii)

题意:

给定一个数组，判断是不是有这样的一对数字，abs(nums[i], nums[j]) <= t and abs(i, j) <= k.


题解:


这里有一种很简单的解决方法，就是维护一个滑动窗口，窗口的大小是k，然后对于每个元素，在窗口中找 x 使得 nums[i]-t <= x <= nums[i]+t，这个华东窗口可以使用map或者set让其有序。

```
public class Solution {
    public boolean containsNearbyAlmostDuplicate(int[] nums, int k, int t) {
        if (nums == null || nums.length == 0 || k <= 0) {
            return false;
        }

        final TreeSet<Integer> values = new TreeSet<>();
        for (int ind = 0; ind < nums.length; ind++) {

            final Integer floor = values.floor(nums[ind] + t);
            final Integer ceil = values.ceiling(nums[ind] - t);
            if ((floor != null && floor >= nums[ind])
                    || (ceil != null && ceil <= nums[ind])) {
                return true;
            }

            values.add(nums[ind]);
            if (ind >= k) {
                values.remove(nums[ind - k]);
            }
        }

        return false;
    }
}
```

这样不对nums进行事先排序，算法复杂度是O(nlgk)

在评论区发现了一种“桶”的解决方案。

```
class Solution(object):
    def containsNearbyAlmostDuplicate(self, nums, k, t):
        # Bucket sort. Each bucket has size of t. For each number, the possible
        # candidate can only be in the same bucket or the two buckets besides.
        # Keep as many as k buckets to ensure that the difference is at most k.
        buckets = {}
        for i, v in enumerate(nums):
            # t == 0 is a special case where we only have to check the bucket
            # that v is in.
            bucketNum, offset = (v / t, 1) if t else (v, 0)
            for idx in xrange(bucketNum - offset, bucketNum + offset + 1):
                if idx in buckets and abs(buckets[idx] - nums[i]) <= t:
                    return True
            
            buckets[bucketNum] = nums[i]
            if len(buckets) > k:
                # Remove the bucket which is too far away. Beware of zero t.
                del buckets[nums[i - k] / t if t else nums[i - k]]
    
        return False
```

这种解法的意思是：

如果 target 不是 0

将数值按照target分块，每个target范围，作为一个块，每个块只记录最近的一个代表数值。

这样做多最多检查左右两个块即可，因为小于 target 的一定不会出现在两个块的范围之外。

那么如何进行更新呢？

对于每个nums[i]，找到那个距离超出目标的代表数字所在的桶删除即可。