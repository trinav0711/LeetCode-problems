class Solution {
public:
    bool isPalindrome(string s) {
        string s1="";
        for(int i=0;i<s.length();++i){
            if(s[i]>='A' && s[i]<='Z')
                s[i]=tolower(s[i]);
            if((s[i]>='a' && s[i]<='z')||(s[i]>='0' && s[i]<='9'))
                s1+=s[i];
        }
        string s2(s1);
        reverse(s2.begin(), s2.end());
        return s1==s2;
    }
};