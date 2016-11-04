```c++
class Solution {
    public:
        bool isPalindrome(int x) {
            if (x < 0)return false;
            short n = 1;
            while (1) {
                int i = x / pow(10, n);
                if (!i)break;
                ++n;
            }


            int y = n - 1;
            int l = n / 2;

            while (l--) {

                if (x%10 == x / int(pow(10, y))) {

                    x = x%int(pow(10, y));
                    x = x / 10;

                    y = y - 2;
                }
                else return false;
            }
            return true;
        }
}
```
