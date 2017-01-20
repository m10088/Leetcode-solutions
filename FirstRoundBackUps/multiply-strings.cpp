#define MAXN 9999
#define MAXSIZE 10
#define DLEN 4

struct BigNum
{

    int a[500];    
    int len;       

    BigNum(){ len = 1;memset(a,0,sizeof(a)); }   
    BigNum(const int);       
    BigNum(const char*);     
    BigNum(const BigNum &);  
    BigNum &operator=(const BigNum &);   

    friend istream& operator>>(istream&,  BigNum&);   
    friend ostream& operator<<(ostream&,  BigNum&);   

    BigNum operator+(const BigNum &) const;   
    BigNum operator-(const BigNum &) const;   
    BigNum operator*(const BigNum &) const;   
    BigNum operator/(const int   &) const;    

    BigNum operator^(const int  &) const;    
    int    operator%(const int  &) const;    
    bool   operator>(const BigNum & T)const;   
    bool   operator>(const int & t)const;      

    string print();       
};

BigNum::BigNum(const char*s)     
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

BigNum BigNum::operator*(const BigNum & T) const   
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
std::string fun(BigNum& b)   
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