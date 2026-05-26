class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<bool> low(26, false), upp(26, false);
        for(char c:word) {
            if(c>='a' && c<='z') low[c-'a']=true;
            else upp[c-'A']=true;
        }
        int ans=0;
        for(int i=0;i<26;++i) {
            if(low[i]&upp[i]) ++ans;
        }
        return ans;
    }
};