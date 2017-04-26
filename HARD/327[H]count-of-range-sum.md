[原题](https://leetcode.com/problems/count-of-range-sum)

题意

题解

```C++
/*其实这个题目和那个count of smaller of right，有异曲同工之妙，但是那个题目使用distance基本上是不行的，
因为需要计算开始的迭代器和目标迭代器的范围，因此复杂度是O(n)，
但是这个题目计算两个迭代器的距离显然不会达到O(n)，因此是可以行的通的*/


/*类似count of smaller of right. 也可以使用MergeSort解决，参考这里http://www.cnblogs.com/grandyang/p/5162678.html */

class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        int res = 0;
        long long sum = 0;
        multiset<long long> sums;
        sums.insert(0);
        for (int i = 0; i < nums.size(); ++i) {
            sum += nums[i];
            res += distance(sums.lower_bound(sum - upper), sums.upper_bound(sum - lower));
            sums.insert(sum);
        }
        return res;
    }        
};


```
