```c++
import re
class Solution(object):
    def romanToInt(self, s):
        """
        :type s: str
        :rtype: int
        """
        m = re.match(r'^(M{0,3})(CM|CD|D?C{0,3})(XC|XL|L?X{0,3})(IX|IV|V?I{0,3})$', s)
        fir = m.group(1)
        sec = m.group(2)
        thr = m.group(3)
        fot = m.group(4)
        res = 0
        res += len(fir)*1000
        
        if len(sec) != 0:
            if sec.find('M') != -1:
                res += 900
            elif sec.find('D') == -1:
                res += 100 * len(sec)
            else:
                if sec[0] == 'D':
                    res += len(sec[1:])*100 + 500
                else:
                    res += 400
        
        if len(thr) != 0:
            if thr.find('C') != -1:
                res += 90
            elif thr.find('L') == -1:
                res += 10 * len(thr)
            else:
                if thr[0] == 'L':
                    res += len(thr[1:])*10 + 50
                else:
                    res += 40
        
        
        if len(fot) != 0:
            if fot.find('X') != -1:
                res += 9
            elif fot.find('V') == -1:
                res += 1 * len(fot)
            else:
                if fot[0] == 'V':
                    res += len(fot[1:])*1 + 5
                else:
                    res += 4
                    
        return re
```
