bool isvow(char c){
    if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u'||c=='A'||c=='E'||c=='O'||c=='I'||c=='U')return true;
    else return false;
}
class Solution {
public:
    string reverseVowels(string s) {
        //éç½®åé³å­ç¬¦
        int p=0;
        int q=s.size()-1;
        while(p<q){
            while(!isvow(s[p])){p++;}
            while(!isvow(s[q])){q--;}
            if(p>=q)break;
            char tmp=s[p];
            s[p]=s[q];
            s[q]=tmp;
            
            p++;q--;
            
        }
        return s;
    }
};