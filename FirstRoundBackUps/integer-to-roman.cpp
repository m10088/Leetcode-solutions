#include<map>
vector<string> ge={"","I","II","III","IV","V","VI","VII","VIII","IX"};
vector<string> shi={"","X","XX","XXX","XL","L","LX","LXX","LXXX","XC"};
vector<string> bai={"","C","CC","CCC","CD","D","DC","DCC","DCCC","CM"};
vector<string> qian={"","M","MM","MMM"};
map<int,int> m;
class Solution {
public:
    string intToRoman(int num) {
        string res;
        int begin=1000;
        while(num/begin==0){begin=begin/10;}//æ¾å°å¼å§çæ°å­æ¯é£ä¸ä½
        while(1){
            
            int tmp=num/begin;
            int flag=num%begin;
            
            if(begin==1000){
                res+=qian[tmp];
            }else if(begin==100){
                res+=bai[tmp];
            }else if(begin==10){
                res+=shi[tmp];
            }else if(begin==1){
                res+=ge[tmp];
                break;
            }
            
            if(flag==0)break;
            else num=num%begin;
            begin=begin/10;
        }
        return res;
    }
};