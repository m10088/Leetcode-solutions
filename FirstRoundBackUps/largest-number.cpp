
template<typename T>

std::string ToString(T x){
    std::stringstream sout;
    sout << x;
    return sout.str();
}
bool cmp(string s,string t){
    string fir=s+t;
    string sec=t+s;
    return fir<sec;
}
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string>res;
        for(int i=0;i<nums.size();i++){
            res.push_back(ToString<int>(nums[i]));
        }
        sort(res.begin(),res.end(),cmp);
        string ans;
        for(int i=nums.size()-1;i>=0;i--){
            ans+=res[i];
        }
        
        for(auto p=ans.begin();(*p)=='0';){
            p=ans.erase(p);
        }
        if(ans=="")return "0";
        else return ans;
    }
};