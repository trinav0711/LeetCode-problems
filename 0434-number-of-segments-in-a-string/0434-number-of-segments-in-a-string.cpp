class Solution {
public:
    int countSegments(string s) {
        int start=0, end=0;
        int ans=0;
        while(start<s.length() && s[start]==' ') ++start;
        while(start<s.length()) {
            end=start;
            while(end<s.length() && s[end]!=' ') ++end;
            ++ans;
            start=end+1;
            while(start<s.length() && s[start]==' ') ++start;
        }
        return ans;
    }
};