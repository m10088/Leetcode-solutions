[原题](https://leetcode.com/problems/find-k-pairs-with-smallest-sums/)

题意：

两个数组，从中分别选择一个数字，组成一个和，这样一共能组成 m * n个和，选择最小的k个和。

题解：

简单的方式，就是使用python的优先队列。

```Python
class Solution(object):
    def kSmallestPairs(self, nums1, nums2, k):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :type k: int
        :rtype: List[List[int]]
        """
       
        return heapq.nsmallest(k, ([u, v] for u in nums1 for v in nums2), key=sum)
```

当然这种方式的效率比较低。

```C++
class Solution {
public:
    vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<pair<int, int>> res;
        if(nums1.empty()||nums2.empty()) return res;
        auto comp = [nums1,nums2](pair<int, int>&a, pair<int, int>&b) {
            return nums1[a.first] + nums2[a.second] > nums1[b.first] + nums2[b.second];
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(comp)> q(comp);
        for (int i = 0;i < nums1.size() && i < k;i++) {
            q.push({ i, 0 });
        }
        for (int i = 0;i < k&&(!q.empty());i++) {
            pair<int, int> temp = q.top();
            q.pop();
            res.push_back({nums1[temp.first], nums2[temp.second]});
            if (temp.second < nums2.size() - 1) q.push({ temp.first,temp.second + 1 });
        }
        return res;
    }
};
```

这种解决方案，是先将第一个数组索引全部放进去，然后动态的放入第二个数组的索引，这个用lambda定义的优先级很漂亮，值的学习。
