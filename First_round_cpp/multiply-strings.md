```c++
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
```
