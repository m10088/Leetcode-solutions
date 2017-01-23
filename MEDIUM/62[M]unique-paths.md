[原题](https://leetcode.com/problems/unique-paths/)

题意：

从左上角到右下角，一共的行走的路径有多少条？

首先想到的解决方案。

```C++
int uniquePaths(int m, int n) {
        vector<vector<int> > path(m, vector<int> (n, 1));
        for (int i = 1; i < m; i++)
            for (int j = 1; j < n; j++)
                path[i][j] = path[i - 1][j] + path[i][j - 1];
        return path[m - 1][n - 1];
    }
```

然后发现可以使用滚动数组。

```C++
 int uniquePaths(int m, int n) {
        if (m > n) return uniquePaths(n, m); 
        vector<int> pre(m, 1);
        vector<int> cur(m, 1);
        for (int j = 1; j < n; j++) {
            for (int i = 1; i < m; i++)
                cur[i] = cur[i - 1] + pre[i];
            swap(pre, cur);
        }
        return pre[m - 1];
    }
```

然后发现其实一维数组就够了。

```Python

class Solution(object):
    def uniquePaths(self, m, n):
        """
        :type m: int
        :type n: int
        :rtype: int
        """
        cur = [1] * m
        for _times_ in range(1, n):
            for i in range(1, m):
                cur[i] += cur[i-1]
        return cur[m-1]
        
```

[Reference](https://discuss.leetcode.com/topic/15265/0ms-5-lines-dp-solution-in-c-with-explanations/2)

