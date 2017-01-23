[原题](https://leetcode.com/problems/find-peak-element/)

题意：

找局部峰值的元素，数组两边默认为是无穷小。

数据中可能有多个，只需要返回一个即可。


首先想到的方法是二分。

```Python
class Solution(object):
    def findPeakElement(self, num):
        """
        :type nums: List[int]
        :rtype: int
        """
        
        l, h = 0, len(num) - 1
        while l < h:
            mid1 = (l + h) / 2
            mid2 = mid1 + 1
            if num[mid1] < num[mid2]:
                l = mid2
            else:
                h = mid1
        return l
```

但是使用顺序查找也行。

```C++
class Solution {
public:
    int findPeakElement(const vector<int> &num) {
        for(int i = 1; i < num.size(); i ++)
        {
            if(num[i] < num[i-1])
            {// <
                return i-1;
            }
        }
        return num.size()-1;
    }
};
```

