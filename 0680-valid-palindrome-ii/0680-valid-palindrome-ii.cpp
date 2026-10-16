class Solution {
private:
    bool isPalin(const string& str, int left, int right) const {
        while(left<right) {
            if(str[left]!=str[right]) return false;
            ++left; --right;
        }
        return true;
    }
public:
    bool validPalindrome(string s) {
        bool done=false;
        int left=0, right=s.length()-1;
        while(left<right) {
            if(s[left]==s[right]) {
                ++left;
                --right;
            }
            else
                return isPalin(s, left+1, right) || isPalin(s, left, right-1);
        }
        return true;
    }
};