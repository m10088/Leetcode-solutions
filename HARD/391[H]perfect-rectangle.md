[原题](https://leetcode.com/problems/perfect-rectangle)

题意

题解

```
class Solution(object):
    def isRectangleCover(self, rectangles):
        """
        :type rectangles: List[List[int]]
        :rtype: bool
        """
        x1, y1, x2, y2 = float('inf'), float('inf'), float('-inf'), float('-inf')
        seter = set()
        sum = 0
        
        for rec in rectangles:
            x1 = min(rec[0], x1)
            y1 = min(rec[1], y1)
            x2 = max(rec[2], x2)
            y2 = max(rec[3], y2)
        
            area = (rec[2] - rec[0]) * (rec[3] - rec[1])
            sum += area
            
            p1 = (rec[0], rec[1])
            p2 = (rec[0], rec[3])
            p3 = (rec[2], rec[3])
            p4 = (rec[2], rec[1])
            
            if p1 not in seter: seter.add(p1)
            else: seter.remove(p1)
            if p2 not in seter: seter.add(p2)
            else: seter.remove(p2)
            if p3 not in seter: seter.add(p3)
            else: seter.remove(p3)
            if p4 not in seter: seter.add(p4)
            else: seter.remove(p4)
            
        
        
        if (x1, y1) not in seter or (x1, y2) not in seter or (x2, y1) not in seter or (x2, y2) not in seter or len(seter) != 4: return False
        return True if sum == (x2-x1) * (y2-y1) else False
            
```