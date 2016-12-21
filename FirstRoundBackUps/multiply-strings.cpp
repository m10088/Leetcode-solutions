#define MAXN 9999
#define MAXSIZE 10
#define DLEN 4

struct BigNum
{

    int a[500];    //å¯ä»¥æ§å¶å¤§æ°çä½æ°
    int len;       //å¤§æ°é¿åº¦

    BigNum(){ len = 1;memset(a,0,sizeof(a)); }   //æé å½æ°
    BigNum(const int);       //å°ä¸ä¸ªintç±»åçåéè½¬åä¸ºå¤§æ°
    BigNum(const char*);     //å°ä¸ä¸ªå­ç¬¦ä¸²ç±»åçåéè½¬åä¸ºå¤§æ°
    BigNum(const BigNum &);  //æ·è´æé å½æ°
    BigNum &operator=(const BigNum &);   //éè½½èµå¼è¿ç®ç¬¦ï¼å¤§æ°ä¹é´è¿è¡èµå¼è¿ç®

    friend istream& operator>>(istream&,  BigNum&);   //éè½½è¾å¥è¿ç®ç¬¦
    friend ostream& operator<<(ostream&,  BigNum&);   //éè½½è¾åºè¿ç®ç¬¦

    BigNum operator+(const BigNum &) const;   //éè½½å æ³è¿ç®ç¬¦ï¼ä¸¤ä¸ªå¤§æ°ä¹é´çç¸å è¿ç®
    BigNum operator-(const BigNum &) const;   //éè½½åæ³è¿ç®ç¬¦ï¼ä¸¤ä¸ªå¤§æ°ä¹é´çç¸åè¿ç®
    BigNum operator*(const BigNum &) const;   //éè½½ä¹æ³è¿ç®ç¬¦ï¼ä¸¤ä¸ªå¤§æ°ä¹é´çç¸ä¹è¿ç®
    BigNum operator/(const int   &) const;    //éè½½é¤æ³è¿ç®ç¬¦ï¼å¤§æ°å¯¹ä¸ä¸ªæ´æ°è¿è¡ç¸é¤è¿ç®

    BigNum operator^(const int  &) const;    //å¤§æ°çnæ¬¡æ¹è¿ç®
    int    operator%(const int  &) const;    //å¤§æ°å¯¹ä¸ä¸ªintç±»åçåéè¿è¡åæ¨¡è¿ç®
    bool   operator>(const BigNum & T)const;   //å¤§æ°åå¦ä¸ä¸ªå¤§æ°çå¤§å°æ¯è¾
    bool   operator>(const int & t)const;      //å¤§æ°åä¸ä¸ªintç±»åçåéçå¤§å°æ¯è¾

    string print();       //è¾åºå¤§æ°
};

BigNum::BigNum(const char*s)     //å°ä¸ä¸ªå­ç¬¦ä¸²ç±»åçåéè½¬åä¸ºå¤§æ°
{
    int t,k,index,l,i;
    memset(a,0,sizeof(a));
    l=strlen(s);
    len=l/DLEN;
    if(l%DLEN)
        len++;
    index=0;
    for(i=l-1;i>=0;i-=DLEN)
    {
        t=0;
        k=i-DLEN+1;
        if(k<0)
            k=0;
        for(int j=k;j<=i;j++)
            t=t*10+s[j]-'0';
        a[index++]=t;
    }
}

BigNum BigNum::operator*(const BigNum & T) const   //ä¸¤ä¸ªå¤§æ°ä¹é´çç¸ä¹è¿ç®
{
    BigNum ret;
    int i,j,up;
    int temp,temp1;
    for(i = 0 ; i < len ; i++)
    {
        up = 0;
        for(j = 0 ; j < T.len ; j++)
        {
            temp = a[i] * T.a[j] + ret.a[i + j] + up;
            if(temp > MAXN)
            {
                temp1 = temp - temp / (MAXN + 1) * (MAXN + 1);
                up = temp / (MAXN + 1);
                ret.a[i + j] = temp1;
            }
            else
            {
                up = 0;
                ret.a[i + j] = temp;
            }
        }
        if(up != 0)
            ret.a[i + j] = up;
    }
    ret.len = i + j;
    while(ret.a[ret.len - 1] == 0 && ret.len > 1)
        ret.len--;
    return ret;
}
std::string fun(BigNum& b)   //éè½½è¾åºè¿ç®ç¬¦
{
    std::stringstream sout;
    int i;
    sout << b.a[b.len - 1];
    for(i = b.len - 2 ; i >= 0 ; i--)
    {
        sout.width(DLEN);
        sout.fill('0');
        sout << b.a[i];
    }
    return sout.str();
}



class Solution {
public:
    string multiply(string num1, string num2) {
        BigNum n1(num1.c_str());
        BigNum n2(num2.c_str());
        BigNum n3=n1*n2;
        return fun(n3);
    }
};