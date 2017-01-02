[原题](https://leetcode.com/problems/additive-numbe)

题意:

给定一个子符串，看是不是由斐波那契数列。"112358"这种就是成立的。


题解:

这道题没有什么好方法，就是暴力回溯，直到找到一个满足题意的为止。

```
class Solution(object):
    def isAdditiveNumber(self, num):
        # 这里保证传入的数字的最开始的一位不是0
        n = len(num)
        if 0<n<3: return False
        
        for i in range(1,n-1):
            if num[i] == '0': # 如果第二个数字是0，单独处理
                a, b = int(num[:i]), 0
                tar = str(a+b)
                # print a, b, tar
                # 先判断是不是base-case的情况
                if tar == num[i+1:]: return True
                # 如果能找到目标数字，并且没有结束，递归的查找
                if tar == num[i+1:i+1+len(tar)] and self.isAdditiveNumber(num[i:]): return True
            else:
                for j in range(i+1,n):
                    a, b = int(num[:i]), int(num[i:j])
                    # 特殊情况，如果两个数字中的任何一个有前导0，那么跳过这种情况
                    if len(num[:i]) > 1 and num[:i][0] == '0':continue
                    if len(num[i:j]) > 1 and num[i:j][0] == '0':continue
                    
                    tar = str(a+b)
                    # 先判断是不是base-case的情况
                    if tar == num[j:]: return True
                    # 如果能找到目标数字，并且没有结束，递归的查找
                    if tar == num[j:j+len(tar)] and self.isAdditiveNumber(num[i:]): return True
                     
                
        return False
```


