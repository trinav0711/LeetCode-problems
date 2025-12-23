class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        set<char> c; int maxLen=0, start=0, end=0;
        while(end < s.length()){
            if(!c.count(s[end]))
                c.insert(s[end]);
            else {
                while(s[start]!=s[end]){
                    c.erase(s[start]);
                    start++;
                }
                start++;
            }
            maxLen=max(maxLen, end-start+1);
            end++;
        }
        return maxLen;
    }
};