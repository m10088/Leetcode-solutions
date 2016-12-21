int GCD(int a, int b){
    return b==0 ? a : GCD(b, a%b);
}
class Solution {
public:
    bool canMeasureWater(int x, int y, int z) {
        if (x+y<z) return false;
        //xæèyä¸º0çæåµ
        if (x+y==z) return true;
        //å©ç¨å¾å°çæå¤§å¬çº¦æ°
        return z%GCD(x, y) == 0;
    }
};