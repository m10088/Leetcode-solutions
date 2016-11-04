```c++
class Solution {
    public:
        vector<int> countBits(int num) {
            if (num == 0) {
                return vector<int>{0};
            }
            int * res = new int [num + 7];
            res[0] = 0;
            int round = 0, index = 0;
            while (1) {
                int flag = 0;
                for (int i = 0; i < (1 << round); i++) {
                    index++;
                    res[index] = res[index - (1 << round)] + 1;
                    if (index == num) {
                        flag = 1;
                        break;
                    }
                }
                round++;
                if (flag) {
                    break;
                }
            }
            return vector<int> (res, res + num + 1);
        }
}
```
