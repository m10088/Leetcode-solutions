```c++
class Solution {
public:
    bool isPerfectSquare(int num) {
        int tmp = floor(sqrt(num)+0.5);
        return tmp*tmp == num;
    }
}
```
