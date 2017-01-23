[原题](https://leetcode.com/problems/binary-watch/)

题意：

小时和分钟都是二进制的手表，给出亮的点的个数，给出可能的时间的组合。

使用combination的库，枚举选择的数字，然后分别求和，组合一下即可，注意时间和分钟的有效的范围。

```Python
class Solution(object):
    def readBinaryWatch(self, num):
        """
        :type num: int
        :rtype: List[str]
        """
        up_list = [1, 2, 4, 8]
        down_list = [1, 2, 4, 8, 16, 32]
        
        import itertools
        ret = []
        for up_num in range(num + 1):
            up = itertools.combinations(range(4), up_num)
            down = itertools.combinations(range(6), num - up_num)
            hour_select, mini_select = [], []
            hour, mini = 0, 0
            for hourcom in up:
                hour = 0 if not hourcom else sum([up_list[x] for x in list(hourcom)])
                hour_select.append(hour)
            for mincom in down:
                mini = 0 if not mincom else sum([down_list[x] for x in list(mincom)])
                mini_select.append(mini)
            for x in hour_select:
                for y in mini_select:
                    if 0<=x<12 and 0<=y<60:
                        ret.append(str(x) + ':' +  str("%02d" % y))
        return ret        
        
            
```