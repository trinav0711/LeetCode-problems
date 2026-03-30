class Solution {
private:
    static inline bool isVowel(char c) {
        if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u')
            return true;
        return false;
    }
public:
    int maxVowels(string s, int k) {
        int ans;
        volatile int count=0;
        for(int i=0;i<s.size() && i<k;++i) {
            if(isVowel(s[i]))
                ++count;
        }
        ans=count;
        for(int i=1;i+k<=s.size();++i) {
            if(isVowel(s[i-1]))
                --count;
            if(isVowel(s[i+k-1]))
                ++count;
            if(count>ans)
                ans=count;
        }
        return ans;
    }
};