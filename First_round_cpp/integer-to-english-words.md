```c++
#include <bits/stdc++.h>
using namespace std;
template < typename T>

std::string ToString(T x) {
    std::stringstream sout;
    sout << x;
    return sout.str();
}

string base_name_[10] = {
    "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten"
};
string onety[9] = {
    "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"
};

string fact[9] = {
    "Error!" , "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"
};


int counter(int num) {
    return ToString < int > (num).size();
}

string get(int n) {
    if (n == 0) return "";
    string ret = "";
    int high = n / 100;
    if (high != 0) ret += (base_name_[high - 1] + " Hundred");

    int rest = n % 100;
    if (rest == 0) return ret;

    if (rest <= 10 && rest >=1) {
        ret += (" " + base_name_[rest - 1]);
        } else if (rest < 20 && rest > 10) {
        ret += (" " + onety[rest - 11]);
        } else {
        int mid = rest / 10;
        ret += (" " + fact[mid - 1]);

        int low = rest % 10;
        if (low == 0) return ret;
        ret += (" " + base_name_[low - 1]);
    }
    
    return ret;
}
```
