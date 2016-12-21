[原题](https://discuss.leetcode.com/topic/14641/my-c-solution-backtracking)

题意：

只能使用1-9之间的数，给定一个target，限制使用的数字的个数，返回所有的解决方案。

```
Input: k = 3, n = 9

Output:

[[1,2,6], [1,3,5], [2,3,4]]
```


简单的回溯问题，但是需要注意返回条件比较多。

```
class Solution(object):
    def combinationSum3(self, k, target):
        """
        :type k: int
        :type target: int
        :rtype: List[List[int]]
        """
        res = []
        # We can only use the digit 1-9
        tmp = [0] * 9
        def dfs(cur, target, depth):
            # print cur, target, depth
            if depth == k or target <= 0 or cur == 10:
                if depth == k and target == 0:
                    res.append(tmp[:k])
                return
            tmp[depth] = cur
            dfs(cur+1, target-cur, depth+1)
            dfs(cur+1, target, depth)
        dfs(1, target, 0)
        return res
```

评论区的一种解法：

将搜索的状态树扁平化了。


```C++
class Solution {
public:
  void combination(vector<vector<int>>& result, vector<int> sol, int k, int n) {
    if (sol.size() == k && n == 0) { result.push_back(sol); return ; }
    if (sol.size() < k) {
      for (int i = sol.empty() ? 1 : sol.back() + 1; i <= 9; ++i) {
        if (n - i < 0) break;
        sol.push_back(i);
        combination(result, sol, k, n - i);
        sol.pop_back();
      }
    }
  }

  vector<vector<int>> combinationSum3(int k, int n) {
    vector<vector<int>> result;
    vector<int> sol;
    combination(result, sol, k, n);
    return result;
  }
};
```