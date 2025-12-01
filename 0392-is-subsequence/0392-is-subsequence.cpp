class Solution {
public:
    bool isSubsequence(string s, string t) {
        if(!s.length()) return true;
        else if(!t.length()) return false;
        int j=0;
        for(int i=0;i<t.length();i++){
            if(t[i]==s[j]) j++;
            if(j>=s.length()) break;
        }
        return j==s.length();
    }
};