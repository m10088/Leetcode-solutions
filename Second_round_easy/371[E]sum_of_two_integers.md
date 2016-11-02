[原题](https://leetcode.com/problems/sum-of-two-integers/)

题意：

不能使用 +， -运算符号，计算两个数字的和。

这道题目正统的是使用C/C++写：

1、输入 a，b。 
2、按照位把ab相加，不考虑进位，结果是 a xor b，即1+1=0 0+0=0 1+0=1，进位的请看下面。
3、计算ab的进位的话，只有二者同为1才进位，因此进位可以标示为 (a and b) << 1 ，注意因为是进位，所以需要向左移动1位。
4、于是a+b可以看成 （a xor b）+ （(a and b) << 1），这时候如果 (a and b) << 1 不为0，就递归调用这个方式吧，因为（a xor b）+ （(a and b) << 1） 也有可能进位，所以我们需要不断的处理进位。

```
class Solution {
public:
    int getSum(int a, int b) {
        
        int tempResult = a & b;
        
        return tempResult == 0 ? a ^ b : getSum(tempResult << 1, a ^ b);
    
    }
};
```
