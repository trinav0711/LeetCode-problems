class Solution {
public:
    string addStrings(string num1, string num2) {
        string ans="";
        int carry=0, i;
        reverse(num1.begin(), num1.end()); reverse(num2.begin(), num2.end());
        string& ref=(num1.length()<num2.length())?num1:num2;
        {
            int diff=num1.length()-num2.length();
            if(diff<0) diff*=-1;
            while(diff--)
                ref.push_back('0');
        }
        for(i=0;i<num1.length();++i) {
            int sum=carry+(num1[i]-'0')+(num2[i]-'0');
            carry=sum>=10?1:0;
            sum%=10;
            ans+=(char('0'+sum));
        }
        if(carry) ans.push_back('1');
        reverse(ans.begin(), ans.end());
        return ans;
    }
};