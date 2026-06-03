class Solution {
public:
    string convertToBase7(int num) {
        if(!num) return "0";
        string ans="";
        bool isPos=true;
        if(num<0) isPos=false;
        num=abs(num);
        while(num) {
            ans.push_back(char('0'+(num%7)));
            num/=7;
        }
        if(!isPos) ans+="-";
        reverse(ans.begin(), ans.end());
        return ans;
    }
};