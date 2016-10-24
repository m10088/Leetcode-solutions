```c++
int GCD(int a, int b){
    return b==0 ? a : GCD(b, a%b);
}
class Solution {
public:
    bool canMeasureWater(int x, int y, int z) {
        if (x+y<z) return false;
        
        if (x+y==z) return true;
        
        return z%GCD(x, y) == 0;
    }
}
```
